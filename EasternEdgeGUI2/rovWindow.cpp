#include "rovWindow.h"

using namespace std;

rovWindow::rovWindow(int g_w, int g_h, const char *g_l)
	: Fl_Window(g_w, g_h, g_l)
{
	resizable(this); //makes the window resizable
	begin();
	color(0x81817800); //changes the window colour
	/////////////////////////////////defines the sliders
	mainPower = new Fl_Value_Slider(60, 60, 40, 160, "MAIN");
	surge = new Fl_Value_Slider(140, 60, 40, 160, "SURGE");
	heave = new Fl_Value_Slider(220, 60, 40, 160, "HEAVE");
	sway = new Fl_Value_Slider(300, 60, 40, 160, "SWAY");
	yaw = new Fl_Value_Slider(380, 60, 40, 160, "YAW");
	pitch = new Fl_Value_Slider(460, 60, 40, 160, "PITCH");
	roll = new Fl_Value_Slider(540, 60, 40, 160, "ROLL");
	/////////////////////////////////sets the limits for the control sliders
	mainPower->bounds(100, 0); 
	surge->bounds(100, 0);
	heave->bounds(100, 0);
	sway->bounds(100, 0);
	yaw->bounds(100, 0);
	pitch->bounds(100, 0);
	roll->bounds(100, 0);
	///////////////////////////////changes the font style of the sliders
	mainPower->labelfont(FL_BOLD);
	surge->labelfont(FL_BOLD);
	heave->labelfont(FL_BOLD);
	sway->labelfont(FL_BOLD);
	yaw->labelfont(FL_BOLD);
	pitch->labelfont(FL_BOLD);
	roll->labelfont(FL_BOLD);
	///////////////////////////////changes the colour of the inside of the slider
	mainPower->color(0xABCDC800);
	surge->color(0xABCDC800);
	heave->color(0xABCDC800);
	sway->color(0xABCDC800);
	yaw->color(0xABCDC800);
	pitch->color(0xABCDC800);
	roll->color(0xABCDC800);
	///////////////////////////////////changes the colour of the slider buttons
	mainPower->selection_color(0x58b5b800);
	surge->selection_color(0x58b5b800);
	heave->selection_color(0x58b5b800);
	sway->selection_color(0x58b5b800);
	yaw->selection_color(0x58b5b800);
	pitch->selection_color(0x58b5b800);
	roll->selection_color(0x58b5b800);
	///////////////////////////////////defines the buttons
	button = new Fl_Radio_Light_Button(76, 270, 30, 30, "1");
	button2 = new Fl_Radio_Light_Button(192, 270, 30, 30, "2");
	button3 = new Fl_Radio_Light_Button(308, 270, 30, 30, "3");
	button4 = new Fl_Radio_Light_Button(424, 270, 30, 30, "4");
	button5 = new Fl_Radio_Light_Button(540, 270, 30, 30, "5");
	button6 = new Fl_Radio_Light_Button(76, 330, 30, 30, "6");
	button7 = new Fl_Radio_Light_Button(192, 330, 30, 30, "7");
	button8 = new Fl_Radio_Light_Button(308, 330, 30, 30, "8");
	button9 = new Fl_Radio_Light_Button(424, 330, 30, 30, "9");
	button10 = new Fl_Radio_Light_Button(540, 330, 30, 30, "0");
	///////////////////////////////creates keyboard shortcuts for the buttons
	button->shortcut('1');
	button2->shortcut('2');
	button3->shortcut('3');
	button4->shortcut('4');
	button5->shortcut('5');
	button6->shortcut('6');
	button7->shortcut('7');
	button8->shortcut('8');
	button9->shortcut('9');
	button10->shortcut('0');
	/////////////////////////////////changes the font style of the button
	button->labelfont(FL_BOLD);
	button2->labelfont(FL_BOLD);
	button3->labelfont(FL_BOLD);
	button4->labelfont(FL_BOLD);
	button5->labelfont(FL_BOLD);
	button6->labelfont(FL_BOLD);
	button7->labelfont(FL_BOLD);
	button8->labelfont(FL_BOLD);
	button9->labelfont(FL_BOLD);
	button10->labelfont(FL_BOLD);
	/////////////////////////////////changes the colour of the actual button
	button->color(0x9EA8A300);
	button2->color(0x9EA8A300);
	button3->color(0x9EA8A300);
	button4->color(0x9EA8A300);
	button5->color(0x9EA8A300);
	button6->color(0x9EA8A300);
	button7->color(0x9EA8A300);
	button8->color(0x9EA8A300);
	button9->color(0x9EA8A300);
	button10->color(0x9EA8A300);
	/////////////////////////////////////changes the colour of the light when the button is pressed
	button->selection_color(0x58b5b800);
	button2->selection_color(0x58b5b800);
	button3->selection_color(0x58b5b800);
	button4->selection_color(0x58b5b800);
	button5->selection_color(0x58b5b800);
	button6->selection_color(0x58b5b800);
	button7->selection_color(0x58b5b800);
	button8->selection_color(0x58b5b800);
	button9->selection_color(0x58b5b800);
	button10->selection_color(0x58b5b800);
	/////////////////////////////////////
	topLeft = new Fl_Value_Input(660, 110, 40, 20, " ");
	topRight = new Fl_Value_Input(830, 110, 40, 20, " ");
	bottomLeft = new Fl_Value_Input(660, 260, 40, 20, " ");
	bottomRight = new Fl_Value_Input(830, 260, 40, 20, " ");
	/////////////////////////////////////
	motorBox = new Fl_Box(705, 135, 120, 120, " ");
	motorBox->box(FL_UP_BOX);
	motorBox->color(0x9EA8A300);
	/////////////////////////////////////
	end();
	show();		//show the window
}
void rovWindow::buttonChanges(bool& b)
											//This function will set all of the button presets
{											//It's up to the pilot what the values are!
	if (button->value() == 1 && b == false)	//Naturally they will need to be updated later
	{
		mainPower->value(50.00);
		b = true;
	}
	if (button2->value() == 1 && b == false)
	{
		mainPower->value(25.00);
		b = true;
	}
}
void rovWindow::updateSliderArray(double sliderValues[]) //This updates every sliders values into an array so they can be accessed and used
{
	sliderValues[0] = mainPower->value();
	sliderValues[1] = surge->value();
	sliderValues[2] = heave->value();
	sliderValues[3] = sway->value();
	sliderValues[4] = yaw->value();
	sliderValues[5] = pitch->value();
	sliderValues[6] = roll->value();
}

int main()
{
	rovWindow window(1000, 450, "Eastern Edge 2018");
	double sv[7];
	bool b = false;
	while (Fl::wait())
	{
		window.buttonChanges(b);
		window.updateSliderArray(sv);
	}
	return 0;
}
