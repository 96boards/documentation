# Build for IVY5661 from source

---  
### There will be 3 steps for building IVY5661 from source.  
- **Step 1:** Prepare the environment.
- **Step 2:** Download the source code.  
- **Step 3:** Choose the board and application profile to make.  

In this example, we assume the path: ``~/workspace`` is your workspace.  

---  
### Step 1: Prepare the environmnet. 
In this section, we should follow the Zephyr official document to install the Zehpyr SDK.  
**1. Download the latest SDK as a self-extracting installation binary:**    
``$ cd ~/workspace``  
``$ wget https://github.com/zephyrproject-rtos/meta-zephyr-sdk/releases/download/0.9.5/zephyr-sdk-0.9.5-setup.run``  
**2. Run the installation binary:**  
 ``$ sh zephyr-sdk-0.9.5-setup.run``  
**3. Follow the installation instructions on the screen.**
The toolchain’s default installation location is ``/opt/zephyr-sdk/``, but it is recommended to install the SDK under your home directory instead.  
**4. To use the Zephyr SDK, export the following environment variables and use the target location where SDK was installed:**
``$ export ZEPHYR_TOOLCHAIN_VARIANT=zephyr``  
``$ export ZEPHYR_SDK_INSTALL_DIR=<sdk installation directory>``  

---  
### Step 2: Download the source code.  
``$ cd ~/workspace``  
``$ mkdir unisoc_zephyr_sdk && cd unisoc_zephyr_sdk``  
``$ repo init -u https://github.com/unisoc/manifests.git -b master``  
``$ repo sync``  
``$ repo start --all master``  

---  
### Step 3: Choose the board and the application profile to make.  
``$ BOARD=96b_ivy5661 PROFILE=repeater make``  

*Note that the default board is ``96b_ivy5661``, while the default profile is ``repeater``. You can choose the application or create the applicaion in folder ``apps/``.*  

After the compilation, the images can be found in the directory ``output/repeater/images/``.  

- ``fdl*.bin`` - Flash downloader  
- ``mcuboot-pubkey*.bin`` - Bootloader  
- ``zephyr-signed-ota*.bin`` - Kernel  
- ``wcn-modem*`` - WCN Modem  

---

