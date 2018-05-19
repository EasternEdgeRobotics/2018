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
	fore = new Fl_Value_Slider(620, 60, 40, 160, "FORE");
	aft = new Fl_Value_Slider(700, 60, 40, 160, "AFT");
	/////////////////////////////////sets the limits for the control sliders
	mainPower->bounds(100, 0); 
	surge->bounds(100, 0);
	heave->bounds(100, 0);
	sway->bounds(100, 0);
	yaw->bounds(100, 0);
	pitch->bounds(100, 0);
	roll->bounds(100, 0);
	fore->bounds(100, 0);
	aft->bounds(100, 0);
	///////////////////////////////changes the font style of the sliders
	mainPower->labelfont(FL_BOLD);
	surge->labelfont(FL_BOLD);
	heave->labelfont(FL_BOLD);
	sway->labelfont(FL_BOLD);
	yaw->labelfont(FL_BOLD);
	pitch->labelfont(FL_BOLD);
	roll->labelfont(FL_BOLD);
	fore->labelfont(FL_BOLD);
	aft->labelfont(FL_BOLD);
	///////////////////////////////changes the colour of the inside of the slider
	mainPower->color(0xABCDC800);
	surge->color(0xABCDC800);
	heave->color(0xABCDC800);
	sway->color(0xABCDC800);
	yaw->color(0xABCDC800);
	pitch->color(0xABCDC800);
	roll->color(0xABCDC800);
	fore->color(0xABCDC800);
	aft->color(0xABCDC800);
	///////////////////////////////////changes the colour of the slider buttons
	mainPower->selection_color(0x58b5b800);
	surge->selection_color(0x58b5b800);
	heave->selection_color(0x58b5b800);
	sway->selection_color(0x58b5b800);
	yaw->selection_color(0x58b5b800);
	pitch->selection_color(0x58b5b800);
	roll->selection_color(0x58b5b800);
	fore->selection_color(0x58b5b800);
	aft->selection_color(0x58b5b800);
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
	topLeft = new Fl_Value_Input(820, 60, 40, 20, " ");
	topRight = new Fl_Value_Input(990, 60, 40, 20, " ");
	bottomLeft = new Fl_Value_Input(820, 210, 40, 20, " ");
	bottomRight = new Fl_Value_Input(990, 210, 40, 20, " ");
	/////////////////////////////////////
	motorBox = new Fl_Box(865, 85, 120, 120, " ");
	motorBox->box(FL_UP_BOX);
	motorBox->color(0xABCDC800);
	goButton = new Fl_Button(900, 125, 50, 40, "GO");
	goButton->color(0x9EA8A300);
	goButton->selection_color(0x58b5b800);
	goButton->labelfont(FL_BOLD);
	goButton->shortcut('g');
	/////////////////////////////////////
	acoustic = new Fl_Toggle_Button(660, 270, 110, 30, "ACOUSTIC");
	electromagnet = new Fl_Toggle_Button(660, 330, 110, 30, "ELECTROMAGNET");
	//
	acoustic->labelsize(12);
	electromagnet->labelsize(12);
	//
	acoustic->labelfont(FL_BOLD);
	electromagnet->labelfont(FL_BOLD);
	//
	acoustic->color(0x9EA8A300);
	electromagnet->color(0x9EA8A300);
	//
	acoustic->selection_color(0x58b5b800);
	electromagnet->selection_color(0x58b5b800);
	/////////////////////////////////////
	depth = new Fl_Value_Output(860, 270, 40, 20, "DEPTH");
	depth->labelfont(FL_BOLD);
	depth->color(0xABCDC800);
	//////////////////////////
	killSwitch = new Fl_Button(60, 380, 110, 30, "EMERGENCY");
	killSwitch->labelsize(12);
	killSwitch->labelfont(FL_BOLD);
	killSwitch->color(0x58b5b800);
	killSwitch->selection_color(FL_RED);
	killSwitch->shortcut('s');
	//////////////////////////////
	end();
	show();		//show the window
}
void rovWindow::buttonChanges(bool b[])
												//This function will set all of the button presets
{												//It's up to the pilot what the values are!
	if (button->value() == 1 && b[0] == false)	//Naturally they will need to be updated later
	{											//The bool array makes it so that the value is set once as the button is hit,
			mainPower->value(50.00);			//instead of being continuously set while the button is on
			b[0] = true;
	}
	if (button2->value() == 1 && b[1] == false)
	{
			mainPower->value(25.00);
			b[1] = true;
	}
	//start of false checking for each button
	if (button->value() == 0)
		b[0] = false;
	if (button2->value() == 0)
		b[1] = false;
	if (button3->value() == 0)
		b[2] = false;
	if (button4->value() == 0)
		b[3] = false;
	if (button5->value() == 0)
		b[4] = false;
	if (button6->value() == 0)
		b[5] = false;
	if (button7->value() == 0)
		b[6] = false;
	if (button8->value() == 0)
		b[7] = false;
	if (button9->value() == 0)
		b[8] = false;
	if (button10->value() == 0)
		b[9] = false;
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
	sliderValues[7] = fore->value();
	sliderValues[8] = aft->value();
}
void rovWindow::getGo(double angleValues[]) //Same use as updateSliderArray, except with the motor angles
{
	if (goButton->value() == 1)
	{
		angleValues[0] = topLeft->value();
		angleValues[1] = topRight->value();
		angleValues[2] = bottomLeft->value();
		angleValues[3] = bottomRight->value();

		topLeft->value(0);
		topRight->value(0);
		bottomLeft->value(0);
		bottomRight->value(0);
	}
}
void rovWindow::toggleBool(bool& a, bool& e)
{
	if (acoustic->value() == 1) //stores if the acoustics button is on or off
	{
		a = true;
	}
	else
	{
		a = false;
	}
	
	if (electromagnet->value() == 1) //stores if the electromagnet button is on or off
	{
		e = true;
	}
	else
	{
		e = false;
	}
}
void rovWindow::killKillKill()
{
	if (killSwitch->value() == 1)
	{
		Fl::delete_widget(this);
		return;
	}
}
/////////////////////////////////////////////////
int main()
{
	rovWindow window(1100, 450, "Eastern Edge 2018");
	double sv[9] = { 0,0,0,0,0,0,0,0,0 };
	double go[4] = { 0,0,0,0 };
	bool b[10] = { false, false, false, false, false, false, false, false, false, false };
	bool a = false;
	bool e = false;
	//loop begin
	while (Fl::wait())
	{
		window.buttonChanges(b);
		window.updateSliderArray(sv);
		window.getGo(go);
		window.toggleBool(a, e);
		window.killKillKill();
	}
	return 0;
}
