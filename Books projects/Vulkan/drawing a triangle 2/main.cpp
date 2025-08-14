#include <cstdint>
#include <cstring>
#include <exception>
#include <sys/types.h>
#include <vector>
#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <map>
#include <optional>

//reporting and propagatins erros
#include <iostream>
#include <stdexcept>
//provides EXIT_SUCESS and EXIT_FAILURE macros
#include <cstdlib> 

/*The callback struct should be passed to the PFN_vkCreateDebugUtilsMessengerEXT function 
 * to create the VkDebugUtilsMessengerEXT object. because this functions is an extension function 
 * its not automatically loaded. we have to look up its address ourselves using vkGetInstanceProcAddr
 * we're going to create our own proxy function that handles this in the background*/

VkResult CreateDebugUtilsMessengerExt(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger){

  //the vkGetInstanceProcAddr will return nullptr if the funciton couldnt be loaded 
  auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "PFN_vkCreateDebugUtilsMessengerEXT");

  if (func != nullptr){
    
    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);

  }else{
    return VK_ERROR_EXTENSION_NOT_PRESENT;
  }

  

}//vkResult 

//the VkDebugUtilsMessengerEXT object also needs to be cleaned up with a call to vkDestroyDebugUtilsMessengerEXT.
void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator){

  auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");

  if (func != nullptr){
    func(instance, debugMessenger, pAllocator);
  }

}//DestroyDebugUtilsMessengerEXT

class HelloTriangleApplication{

  VkQueue graphicsQueue;

  VkDevice device;

  const uint32_t WIDTH = 800;

  const uint32_t HEIGHT = 600;

  const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

  #ifndef NDEBUG
    const bool enableValidationLayers = false;
  #else
    const bool enableValidationLayers = true;
  #endif

  /**The callback returns a boolean that indicates 
   * if the Vulkan call that triggered the validation layer message should be aborted 
   * **/

  //the first parameter specifies the severity of the severity of the message 
  //the pCallbackData parameters refers to a VkDebugUtilsMessengerCallbackDataEXT struct containing
  //the details of the message itself:
  //pMessage: Debug message as a null-terminated string 
  //pObjects: Array of Vulkan object handles related to the message 
  //objectCount: Number of objects in a array 
  //the pUserData parameter contains a pointer that allows you to pass your own data to it
  static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
      VkDebugUtilsMessageTypeFlagsEXT messageType,
      const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
      void* pUserData){

    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
  }//static VKAPI_ATTR

  public: 
    void run(){
      //initialize window 
      initWindow();
      //initiation vulkan functions
      initVulkan();
      //start to render frames
      mainLoop();
      //deallocate resources
      cleanup();
    }

  private:

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger; 
 
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    GLFWwindow* window;

    void initWindow(){

      //Initializing the GLFW library
      glfwInit();

      //need to tell it to not create an OPENHL context
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

      //disabling resizing windows 
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    }

    void initVulkan(){
      
      //the very first thing to do is initializa the Vulkan library by creating an instance
      createInstance();
      setupDebugMessenger();
      pickPhysicalDevice();
      createLogicalDevice();

    }//iniVulkan
    

    void createLogicalDevice(){

      //SPECIFYING THE QUEUES TO BE CREATED
      
      /*The creation of a logical device involves specifying a bunch of details in structs again,
       * of which the first one will be VkDeviceQueueCreateInfo. 
       * This structure describes the number of queues we want for a single queue family 
       * right now we are only interested in a queue with graphics capabilities */
      QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

      /*The currently availabel drivers will only allow you to create a small number of
       * queues for each queue family and you dont really need more than one.
       * thats because you can create all the command buffers on multiple threads and then 
       * submit them all at once on the main thread with a single low-overhead call*/

      VkDeviceQueueCreateInfo queueCreateInfo{};

      queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
      queueCreateInfo.queueCount = 1;
      
      /*Vulkan lets you assign priorities to queues to influence the scheduling of a command buffer 
       * execution using floating point numbers between 0.0 and 1.0 
       * this is required even if there is only a single queue*/
      float queuePriority = 1.0f;
      queueCreateInfo.pQueuePriorities = &queuePriority;

      //Specifying used device features  
      /*The next information to specify is the set of device features that we'll be using 
       * these are the features that we queried support for with vkGetPhysicalDeviceFeatures 
       * in the previous chapter, like geometry shaders. right now we dont need anything special, so 
       * we can simply define it and leave everything to VK_FALSE */
      VkPhysicalDeviceFeatures deviceFeatures{};

      //CREATING THE LOGICAL DEVICE 

      /*The remainder of the information bears a resemblance to the VkInstanceCreateInfo struct 
       * and requires you to specify extensions and validation layers. The difference is that 
       * these are device specific this time*/

      VkDeviceCreateInfo createInfo{};
      createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  
      createInfo.pQueueCreateInfos = &queueCreateInfo;
      createInfo.queueCreateInfoCount = 1;
      
      createInfo.pEnabledFeatures = &deviceFeatures;

      //setting them to be compatible with older implementations
      
      createInfo.enabledExtensionCount = 0;

      if (enableValidationLayers){

        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();

      }else{
        createInfo.enabledLayerCount = 0;
      }//if enableValidationLayers

     
      /*The parameters are the physical device to interface with, the queue and usage info we just 
       * specified, the option allocation callbacks pointer and a pointer to a variable to store the 
       * logical device handle in. Similarly to the instance creation functions, this call can 
       * return errors based on enabling non-existent extensions or specifying the desired usage 
       * of unsupported features */
      

      if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS){

        throw std::runtime_error("falied to create logical device");

      }


    }//create


    //after initializing the Vulkan library through a VkInstace we need to look for and select a 
    //graphics card in the system that supports the features we need 
    void pickPhysicalDevice(){

      //this object will be implicitly destroyed when the VkInstance is destroyed
      VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

      //listing te graphics cards is very similar to listing extensions and starts with querying 
      //just the number 

      uint32_t deviceCount = 0;
      vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

      //if there are 0 devices with Vulkan support then theres no point going further
      if (deviceCount == 0){
        throw std::runtime_error("failed to find GPUs with Vulkan support!");
      }
       
      //otherwise we can now allocate an array to hold all of the VkPhysicalDevice handles
      std::vector<VkPhysicalDevice> devices(deviceCount);
      vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data())  ;
      
      //check if any of the physical devices meet the requirements 
      for (const auto& device : devices){

        if (isDeviceSuitable(device)){
          physicalDevice = device;
          break;
        }

      }//for 
      
      if (physicalDevice == VK_NULL_HANDLE){
        throw std::runtime_error("failed to find a suitable GPU!");
      }

 

    }//pickPhysicalDevice


    //now we need to evaluate each of them and check if they are suitable for the operations we 
    //want to perform 

    bool isDeviceSuitable(VkPhysicalDevice device){
      
      QueueFamilyIndices indices = findQueueFamilies(device);

      return indices.isComplete();

    }//isDeviceSuitable

    /*separate debug utils messenger specifically for the vkCreateDebugUtilsMessengerEXT that
     * that requires a valid instance to have been created and vkDestroyDebugUtilsMessengerEXT must
     * be called before the instance is destroyed
     * it requires you to simply pass a pointer to a VkDebugUtilsMessengerCreateInfoEXT struct 
     * in the pNext extension field of VkInstanceCreateInfo*/

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo){

      createInfo = {};

      createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

      createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                                   VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                   VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

      createInfo.messageType = 
          VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
          VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
          VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

      createInfo.pfnUserCallback = debugCallback;

    }//populateDebugMessengerCreateInfo

    /*We need to check which queue families are supported by the device 
     * and which one of these supports the commands that we want to use */

    struct QueueFamilyIndices{
      //std::optional is a wrapper that contains no value until you assign something to it.
      std::optional<uint32_t> graphicsFamily;

      //generic check to the struct itself
      bool isComplete(){
        return graphicsFamily.has_value() ;
      }

    };
    
    //findQueueFamilies looks for all the queue families we need 
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device){
      
      QueueFamilyIndices indices;
      //logic to find graphics queue family
      
      //retrieving the list of queue families
      uint32_t queueFamilyCount = 0;
      vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

      //VkQueueFamilyProperties struct contains some details about the queue 
      //including the type of operations that are supported and the number of queues that can be created
      //We need to find at least one queue family that supports VK_QUEUE_GRAPHICS_BIT
      std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
      vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

      int i = 0;
      for (const auto& queueFamily : queueFamilies){

        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT){
          indices.graphicsFamily = i;
        }
       
        if (indices.isComplete()){
          break;
        }

        i++;

      }//for 


      return indices;
      

    }//findQueueFamilies


    void setupDebugMessenger(){
     
      /*The callback returns a boolean that indicates if the Vulkan call that triggered the 
       * validation layer message should be aborted 
       * if the callback returns true, then the call is aborted with the VK_ERROR_VALIDATION_FAILED_EXT
       * This is normally only used to test the validation layers themselves, so you should always
       * return VK_FALSE 
       *
       * even the debug callback in Vulkan is managed with a handle that needs to be explicitly created
       * and destroyed
       *
       */

      if (!enableValidationLayers) return;

      VkDebugUtilsMessengerCreateInfoEXT createInfo{};

      createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
      
      //the messageSeverity field allows you to specify all the types os severities you would like 
      //your callback to be called for 
      createInfo.messageSeverity = 
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        
      //messageType field lets you filter which types of messages your callback is notified about
      createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

      //pfnUserCallback field specifies the pointer to the callback function 
      createInfo.pfnUserCallback = debugCallback;

      //you can pass a pointer to the pUserData field 
      //which will be passed along to the callback function via the pUserData parameter 

      createInfo.pUserData = nullptr; //optional

      

    }//setupDebugMessenger

    void mainLoop(){

      //keep app running until either an errors or window is closed
      while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
      }


    }//mainLoop

    void cleanup(){
     
      //logical devices dont interact directly with instance, which is why its not included as a parameter 

      vkDestroyDevice(device, nullptr);

      if (enableValidationLayers){
        DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
      }

      //should be only destroyed right before the program exits
      vkDestroyInstance(instance, nullptr);

      glfwDestroyWindow(window);

      glfwTerminate();

    }//cleanup
    

    void createInstance(){
      
      if (enableValidationLayers && !checkValidationLayerSupport()){
        throw std::runtime_error("validation layers requested, but not available!");
      }

      //filling a struct with some infomration about the app 
      VkApplicationInfo appInfo{};

      //many structs in Vulkan require you to explicitly specify the type in the sType member
      appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

      appInfo.pApplicationName = "Hello Triangle";

      appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
      appInfo.pEngineName = "No Engine";
      appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
      appInfo.apiVersion = VK_API_VERSION_1_0;

      //////////////////////////////////////

      //This next struct is not optional and tells the Vulkan driver which global extensions and validation layers we want to use
      //apply to enterine program and not a specific device 

      VkInstanceCreateInfo createInfo{};

      createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

      createInfo.pApplicationInfo = &appInfo;

      //the debugCreateInfo is places outside the if statement to ensure that its not destroyed
      //before the vkCreateInstance call
      VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
      

      //modifying VkInstanceCreateInfo struct instatiation to include the validation layer names if theyre enabled
      if (enableValidationLayers){
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();

        populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;

      }else{
        createInfo.enabledLayerCount = 0;

        createInfo.pNext = nullptr;
      }

      if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS){
        throw std::runtime_error("failed to create instance!");
      }


      //need an extension to interface with the window system
      uint32_t glfwExtensionCount = 0;
      const char** glfwExtensions;

      glfwExtensions = 
              glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

      createInfo.enabledExtensionCount = glfwExtensionCount;
      createInfo.ppEnabledExtensionNames = glfwExtensions;

      //determine the global validation layers to enable 
      createInfo.enabledLayerCount = 0;

      //after specified everything Vulkan needs to create an instance, 
      //we can finally issue with the vkCreateInstance
      VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

      if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS){
        throw std::runtime_error("Faile to create instance!");
      }

      //to allocate an array to hold the extension details we first nedd to know how many there are
      uint32_t extensionCount = 0;

      vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
      
      /*
      //allocate an array to hold the extension details
      std::vector<VkExtensionProperties> extensions(extensionCount);

      //querying extension details 
      vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

      std::cout << "available extensions:\n";

      for (const auto& extension : extensions){

        std::cout << '\t' << extension.extensionName << '\n';

      }//for 
      */ 

      auto extensions = getRequiredExtensions();
      createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());

      createInfo.ppEnabledExtensionNames = extensions.data();

    }//create instance 

    //check if all of the requested layers are available 
    bool checkValidationLayerSupport(){

      uint32_t layerCount;
      //list all of the available layers 
      vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

      std::vector<VkLayerProperties> availableLayers(layerCount);
      vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

      
      //check if all of the layers in validationLayers exist in the availableLayers list 

      for (const char* layerName : validationLayers){
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers){

          if (strcmp(layerName, layerProperties.layerName) == 0){
            layerFound = true;
            break;
          }

        }//for 

        if (!layerFound){
          return false;
        }

      }//for

      return true;

    }//checkValidationLayerSupport

    /*to set up a callback in the program to handle messages and te associated details,
     * we have to set up a debug messenger with a callback using the VK_EXT_debug_utils extension */

    //create a function that return the reuqired list of extensions based on whether validation layers are enabled or not
    std::vector<const char*> getRequiredExtensions(){
      uint32_t glfwExtensionCount = 0;
      const char** glfwExtensions;
      glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

      std::vector<const char*> extensions(glfwExtensions, glfwExtensions+glfwExtensionCount);

      if (enableValidationLayers){
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
      }
      
      return extensions;
    }//getRequiredExtensions

};//class triangle


int main (int argc, char *argv[]) {
  
  HelloTriangleApplication app;

  try{
    app.run();
  }catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return 0;
}
