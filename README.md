ESP32-S3 MACRO PAD
 
Its a  simple 6key USB macro pad made with an ESP32-S3 and an OLED display.
The display shows "Connected" or "Disconnected" (USB status).
 
KEYS
  Key 1 (GPIO 18)  Copy
  Key 2 (GPIO 35)  Paste
  Key 3 (GPIO 21)  Cut
  Key 4 (GPIO 38)  Open YouTube
  Key 5 (GPIO 37)  Open Safari
  Key 6 (GPIO 36)  Close tab
 
DISPLAY
  SDA -> GPIO 45
  SCL -> GPIO 46
 
WIRING
  Each switch goes between its GPIO pin and GND,3v3.
 
SETUP
  1. Install the Arduino IDE and the ESP32 board package.
  2. Install libraries: Adafruit SSD1306 and Adafruit GFX Library.
  3. In Tools, set:
       Board: ESP32S3 Dev Module
       USB Mode: USB-OTG (TinyUSB)
       USB CDC On Boot: Disabled
  4. Open macropad.ino, then upload it to the board.
  5. Plug the board into your computer by USB.

 For window user 
  - Shortcuts use the Command key (Mac).
    For Windows, change KEY_LEFT_GUI to KEY_LEFT_CTRL in the code.
  
 <img width="1710" height="1112" alt="Screenshot 2026-10-11 at 14 08 32" src="https://github.com/user-attachments/assets/5c13d901-dbe7-49fb-9a48-5116dcbb3ccb" />

