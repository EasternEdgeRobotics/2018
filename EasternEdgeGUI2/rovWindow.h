#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Radio_Light_Button.H>
#include <FL/Fl_Value_Input.H>
#include <array>

using namespace std;

/*
* The GUI for Eastern Edge! User interface for controlling the ROV.
* Has 7 sliders, 1 for total power and the rest for the 6 axis of motion
* 10 buttons, each for a different preset for motion
* This is Ver. 2! Hopefully new and improved...
*/

class rovWindow : public Fl_Window
{
public:
	rovWindow(int w, int h, const char *l = 0);
	~rovWindow() {}
	void buttonChanges(bool& b);
	void updateSliderArray(double sliderValues[]);
	Fl_Value_Slider* mainPower;
	Fl_Value_Slider* surge;
	Fl_Value_Slider* heave;
	Fl_Value_Slider* sway;
	Fl_Value_Slider* yaw;
	Fl_Value_Slider* pitch;
	Fl_Value_Slider* roll;
	////////////////////////////////
	Fl_Radio_Light_Button* button;
	Fl_Radio_Light_Button* button2;
	Fl_Radio_Light_Button* button3;
	Fl_Radio_Light_Button* button4;
	Fl_Radio_Light_Button* button5;
	Fl_Radio_Light_Button* button6;
	Fl_Radio_Light_Button* button7;
	Fl_Radio_Light_Button* button8;
	Fl_Radio_Light_Button* button9;
	Fl_Radio_Light_Button* button10;
	////////////////////////////////
	Fl_Value_Input* topLeft;
	Fl_Value_Input* topRight;
	Fl_Value_Input* bottomLeft;
	Fl_Value_Input* bottomRight;
	////////////////////////////////
	Fl_Box* motorBox;
};
