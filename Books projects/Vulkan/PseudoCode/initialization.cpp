#include <cstdint>
#include <vector>
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_core.h>

int main (int argc, char *argv[]) {
  
  //****1. Enumarae Instance Layer Properties
  //Vulkan first communicates with the loader and locates the driver
  //the driver exposes  anumber of extensions and layers
  //Get number of instance layers
  uint32_t instanceLayerCount;

  //Use second parameter as NULL to return the layer count 
  vkEnumerateInstanceLayerProperties(&instanceLayerCount, NULL);

  VkLayerProperties *layerProperty = NULL;

  vkEnumerateInstanceLayerProperties(&instanceLayerCount, 
                                      layerProperty);


  //Get the extensions for each available instance layer 
  for (layer : layerProperty){
    VkExtensionProperties *instanceExtensions;

    res = vkEnumerateInstanceLayerProperties(layer_name, &instanceExtensionCount, instanceExtensions);

  }


  /** 2. Instance Creation**/

  //Vulkan instance object
  VkInstance instance;
  VkInstanceCreateInfo instanceInfo = {};

  //Specify layer names that needs to be enabled on instance.
  instanceInfo.ppEnabledLayerNames = {
                                      "VK_LAYER_LUNARG_standard_validation",
                                      "VK_LAYER_LUNARG_object_tracker"};

  //Specify extensions that needs to be enabled on instance 
  instanceInfo.ppEnabledExtensionNames = {
                                          VK_KHR_SURFACE_EXTENSION_NAME,
                                          VK_KHR_WIN32_SURFACE_EXTENSION_NAME
                                          };

  //create the instance object 
  vkCreateInstance(&instanceInfo, NULL, &instance);

  //**3. Enumerate physical devices**///

  VkPhysicalDevice gpu; //Physical Device 

  uint32_t gpuCount; // physical device count 

  std::vector<VkPhysicalDevice> gpuList; //list of physica devices 

  //get number of GPU count 
  vkEnumeratePhysicalDevices(instance, &gpuCount, NULL);

  //get GPU information
  vkEnumeratePhysicalDevices(instance, &gpuCount, gpuList);


  /***4. CREATE DEVICE ****/ 

  //Get Queue and Queue type
  vkGetPhysicalDeviceQueueFamilyProperties(gpu, &queueCount, queueProperties);
  
  //Get the memory properties from the physical device or GPU 
  vkGetPhysicalDeviceMmeoryProperties(gpu, &memoryProperties);

  //get the physical device or GPU properties 
  vkGetPhysicalDeviceProperties(gpu, &gpuProps);

  //Create the logical device object from physical device 
  vkDeviceCreateInfo deviceInfo = {};
  vkCreateDevice(gpuList[0], &deviceInfo, NULL, &device);

  /**5. PRESENTATION INITIALIZAITON**/

  //create an empty window
  xcb_create_window(...); //LINUX

  //Query WSI extensions, store it as functions pointers. For example:
  //vkCreateSwapChainKHR, vkCreateSwapChainKHR 
  //Create an abstract surface object 

  vkWin32SurfaceCreateInfo createInfo = {};

  vkCreateWin32SurfaceKHR(instance, &createInfo, NULL, &surface);

  //Amoung all queues, select a queue that supports presnetation

  foreach Queue in All Queues{

    vkGetPhysicalDeviceSurfaceSupportKHR(
        gpu, queueIndex, surface, &isPresentationSupported
        ); 
    //Store this queue's index 
    if (isPresentationSupported){
        graphicsQueueFamilyIndex = Queue.index;
      break;
    }

  }//foreach

  //Acquire compatible queue supporting presentation 
  //and is also a graphics queue 

  vkGetDeviceQueue(device, graphicsQueueFamilyIndex, 0, &queue);

  //Allocate memory for total surface format count 
  uint32_t formatCount;
  
  vkGetPhysicalDeviceSurfaceFormatsKHR(gpu, surface, &formatCount, NULL);

  VkSurfaceFormatKHR *surfaceFormats = allocate memory(formatCount * VkSurfaceFormatKHR);

  //Grab the surface format into VkSurfaceFormatKHR objects  

  vkGetPhysicalDeviceSurfaceFormatsKHR(gpu, surface, &formatCount, surfaceFormats);
    
  

  return 0;
}
