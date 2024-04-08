The Fan Speed Controller with Temperature System is the mini-project #3 of Standard Embedded Systems Diploma at Edges for Training Academy, under the expert guidance of Mohamed Tarek.

This project involves developing a system that controls the speed of a fan depending on the temperature. It utilizes various drivers including GPIO, ADC, PWM, LM35 Sensor, LCD and DC-Motor for functionality.

> MCAL: GPIO, ADC, and TIIMER0_PWM.

> HAL: LCD, TEMP_SENSOR, and DC_MOTOR.


The LM35 is a precision integrated-circuit temperature sensor whose output voltage is linearly proportional to Celsius temperature. It doesn't require any external calibration to provide typical accuracies of ±1/4°C at room temperature and ±3/4°C over a full -55°C to 150°C temperature range. This makes it an excellent choice for temperature sensing applications in various projects.

Here is some screenshots from the system:

1. The user interface:

![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/fade19d4-6d20-46fe-808b-46897c40f48a)



2. While fan OFF (Temp < 30):
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/67d42d46-1a95-458c-a26a-23ef598acd32)

![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/073ebbff-d2d1-4d7b-9459-685ffde371d6)



3. While Fan ON with 25% speed (30 <= Temp < 60)
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/19ecdb94-8b88-4480-9f38-b6952355766e)

![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/f5d3237d-6f2d-4d16-a6cb-b6550d2390df)



4. While Fan ON with 50% speed (60 <= Temp < 90)
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/4fe5cfd1-1790-4b51-bc77-5faac3e53eec)

![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/94bbb343-8fde-4da1-bef3-d29edf471313)



5. While Fan ON with 75% speed (90 <= Temp < 120)
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/3dce4335-3bac-4e65-9cac-8be95ad90a1c)

![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/48b56024-2eae-4b3d-a5e8-0d38f13579e3)

6. While Fan ON with 100% speed ( Temp >= 120)
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/94e9210e-dc6d-49fa-8fff-c72b3776b323)
![image](https://github.com/dev-Youssef-Ahmed/Fan-Speed-Controller-with-Temperature/assets/153888401/926d29b1-da4d-43f4-bf1d-87823deb57e8)

Note: The proteus file contain two sheets, the user interface sheet, and the background sheet.
