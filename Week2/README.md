#PROJECT CREATION ON Silicon Lab
  
    1) To Install the Simplicity Studio v5 
    2) To Connect the Board on pc Through the USB BRD4401C Rev A01 (or) EFR32xG28
  <img width="937" height="918" alt="image" src="https://github.com/user-attachments/assets/9495aaa3-b1b2-4286-a19d-47b31edc40e7" />
    
    3) Create the Project Click "Create new Project"
    4) To Open new Window To select "Target/SDK" and click the Next
    5) To choose the Sample BLE Project "Bluetooth_SoC_Blinky" an dclick next
  <img width="934" height="413" alt="image" src="https://github.com/user-attachments/assets/124fb70a-87c0-4037-ac9e-2bcefd86796d" />
  
    6) Enter the "Project Name" 
    7) Then to Create the Bootloader To flash the Board
    8) To create the Project follow these above steps
    9) choose the Sample Bootloader Project "Bluetooth OTA ADF " and click next

#TO FLASH THE BOARD AND RUN THE APPLICATION

    1) To build the project "Bluetooth_SoC_Blinky" and "BootloaderProject"
    2) To flash the Project Right click on the  
        Bootloader: binaries -> .hex file-> click Erace and Program 
        Bluetooth_SoC_Blinky: binaries -> .hex file -> Program
    3) To debug the Project 
    4) To open the SI Connect or NFR Connect on mobile
    5) to Access the board LED using Mobile through the BLE
