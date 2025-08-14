#include <cstdint>
#include <cstring>
#include <exception>
#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream> 
#include <stdexcept>
#include <cstdlib>
#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
  
    

  //all the useful standard validation is bundled into this layer 
    "VK_LAYER_KHRONOS_validation"

};

#ifdef NDEBUG
  const bool enableValidationLayers = false;
#else 
  const bool enableValidationLayers = true;


#endif

//checking if all of the requested layers are available
bool checkValidationLayerSupport(){

  uint32_t layerCount;

  //list all of the available layers 
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  
  return false;
}

class HelloTriangleApplication{


  //every Vulkan object that we create needs to be explicitly destryed
  //when we  no longer need it 

  public:
    void run(){
      
      initWindow();

      //start vulkan objects 
      initVulkan();
      //start rendering frames 
      mainLoop();
      //deallocate the resources
      cleanup(); 

    }//run 


  /*the program it self is wrapped into a class where we'll store the Vulkan aobjects
   * as private calss members and add functions to initiate each of them, which will 
   * be called from the initVulkan function */

  private:

    GLFWwindow * window;
    VkInstance instance;

    void createInstance(){

      if (enableValidationLayers && !checkValidationLayerSupport()){
        //throw std::runtime_error("validation layers requested, but not available!");
      }

      VkApplicationInfo appInfo{};
      
      //information about our application 
      //provides information to the driver in order to optimize our application 
      
      //a lot of information in Vulkan is passed through structs
      //instead of function parameters 
      appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

      appInfo.pApplicationName = "Hello Triangle";

      appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);

     appInfo.pEngineName = "No Engine";

      appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);

      appInfo.apiVersion = VK_API_VERSION_1_0;

  
      //tells the Vulkan driver which global extensions and validation layers
      //we want to use. global here means that they apply to the entire program
      //and not a specific device

      VkInstanceCreateInfo createInfo{};

      createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

      createInfo.pApplicationInfo = &appInfo;

      //Vulkan is a plataform agnostic API, which means that you need an extension 
      //to interface with the window system
      //GLFW has a handy built-in function that returns the extension(s) it needs 
      //to do that
  
      uint32_t glfwExtensionCount = 0;
      const char** glfwExtensions;

      glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

      createInfo.enabledExtensionCount = glfwExtensionCount;

      createInfo.ppEnabledExtensionNames = glfwExtensions;

      //determine the global validation layers to enable 
      createInfo.enabledLayerCount = 0;

      VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

      if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS){
        throw std::runtime_error("failed to create instance!");
      }

    }//createInstance 

    void initWindow(){
      
      //initialize glfw library
      glfwInit();

      //telling to not create an OPENGL context 
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      //disabling it for now because resized windows takes special care
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);


    }//initWindow 

    void initVulkan(){
      
      /*the instance is the connection between your application and the vulkan library
      and creating it involves specifying some details about your application 
      to the driver */

        createInstance();


    }//init vulkan

    void mainLoop(){

      while(!glfwWindowShouldClose(window)){

        glfwPollEvents();

      }//while !glfwWindowShouldClose
      

    }//mainLoop 

    void cleanup(){
      
      //destroying the window 
      glfwDestroyWindow(window);

      //terminating GLFW itself
      glfwTerminate();

    }//cleanup 


}; //HelloTriangleApplication


int main(){
  HelloTriangleApplication app;

  
  try{
    app.run();
  }catch(const std::exception& e){

    std:: cerr << e.what() << std::endl;
    return EXIT_FAILURE;

  }

  return EXIT_SUCCESS;
}//main 
