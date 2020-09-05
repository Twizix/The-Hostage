#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <mmsystem.h>
#include <math.h>
#include <wincon.h>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using std::getline;
string playersName;
int health;
int respect;
double damagemodifier;
bool damage;
bool respectdamage;
bool gain;
void intro();
void punch();
void titleScreen();
void timer();
void questionintro();
void questionintro2();
void questions();
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();
void question12();
void question13();
void question14();
void question15();
void question16();
void question17();
void question18();
void question19();
void healthbar();
void respectbar();
void respectbargain();
int punchsound();
int music();
void gun();
int gunshot();
void littlebitch();
void aggresiveending();
void dumbending();
int introstory();
void ending();
void credits();
void slow_print(const string&, unsigned int);

int main()
{ // Title and Menue screen
	system("color 02");
	//Change console size << http://stackoverflow.com/questions/21238806/how-to-set-output-console-width-in-visual-studio
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 675, 600, TRUE); // first# width, second# height
	HANDLE hColor;
	hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	titleScreen();
	music();
	int var;
	cout << "                                  Play Game = 1                                 "
		 << "                                  Exit Game = 2                                 " << endl;
	cin >> var;
	switch (var)
	{
	case 1:  1;
		system("cls");
		introstory();
		system("cls");
		damage = false;
		respectdamage = false;
		health = 100;
		respect = 100;
		damagemodifier = 1;
		intro();
		sleep_for(seconds(0));
		sleep_for(seconds(0));
		questions();
		system("pause");
		break;
	case 2: 2;
		terminate;//close window
		break;
	case 3: !1 | !2;
		system("cls");
		credits();
		system("pause");
	}

	return 0;
}

void titleScreen()
{
	cout << "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                ";
	sleep_until(system_clock::now() + seconds(1));
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[]       ,@''@, @@@@@@@@@@@@',@@@'@@   ,@@@      ,@@@@@@@@,    @  ,@@,        []";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[]      ;@@..,        '@'       ,@'    @@@'     @'  ,@' '@@@  @@ @  ,@        []";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[]       '@@@@@      ,@       ,@'    ,@'@@     '  ,@'     @@  @ @,  @'        []";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[] '@@.,    @'   , ,@'       @@    ,@' @@@  @@.,,@'    ,.@'  @@  @@'          []";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[]   '@@@@@'    '@@'        '@@@@@@'  ,@@'   '@@@@@@@@''                      []";
	sleep_until(system_clock::now() + milliseconds(50));
	cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
	sleep_until(system_clock::now() + seconds(4));
	system("cls");
	cout << "================================================================================"
		<< "    @@@@@@@@@                  @@  ,,         @@@@,                             "
		<< "   @,   @@  @@                 @   @         @@* @  @                           "
		<< "   @@@  @   @@                @@  @@          @@   @@                           "
		<< "    @  @@   @ @@,  @@@,    ,*@@**@@*.@@.**.@@. @  *@**   @@@,  @@@@,   @@@@,    "
		<< "       @   @@* @  @ **    @  @@  @  @  @  @@   @@ @@   *@  @  @@ .@   @@ **     "
		<< "   @@@@@   @  @@@ @@@@@*  *@@*  @@  *@@*  *@@@@@* @@@@@ *@*@@@ *@@@@*  @@@@@*   "
		<< "============================================================   @ @   ==========="
		<< "                                                               *@               "
		<< "                                                                                "
		<< "                        .@@@@@                    @@@@@@@                       "
		<< "                       @      @                 @@       @                      "
		<< "                      @        @              @@          @                     "
		<< "                      @         @            @    ,    @@@@                     "
		<< "                   @@**@.       @           @    @   @@    @@@                  "
		<< "                 @'      @,      @          @    @ @' . @@    @@                "
		<< "               @@      @, @      @         @    @   @.'''  .    @@              "
		<< "              ###     '''.@      @         @    @    @@@@@'   #####             "
		<< "              ##### @....'       @@===========@@         V ###### @             "
		<< "             @  ###@  V           @           @           ## @     @            "
		<< "            @     @##V@           @@         @@           @V @     @            "
		<< "           @      @ # @            @         @            @ V@      @           "
		<< "          @      @ V  @            @@       @@            @  @      @           "
		<< "         @       @V   @              @@   @@             @   @       @          "
		<< "         @      @      @               @@@               @    @      @          "
		<< "         @     @       @                                 @    @      @          "
		<< "                                                                                " << endl;
}

void intro()
{
	//Introducing the player to the game
	sleep_until(system_clock::now() + milliseconds(1000));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	cout << "*Thunder*";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	cout << endl << "**Eyes open**";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"Where am I?\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	cout << endl << "*Thunder*";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"A storm?\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"I hear rain but I think I'm inside.\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"Cold, but no wind...\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"I must be inside.\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	cout << endl << "*Lightning*";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"The lights are off. But where am I?\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"think, THINK!\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"Today is...Wednesday! No, Thursday!\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"Second week of April, ahhhh 2020.\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"Last thing I remember, I was planting C4 under a bridge,"
		<< endl << "and then I was on a computer...\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"No no I was on the computer first...or was I?\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "\"Shit...shit..\"" << endl;
	sleep_until(system_clock::now() + seconds(2));
	cin.ignore();
	cout << "\"What's my name..: ";
	getline(cin, playersName);
	sleep_until(system_clock::now() + seconds(2));
	if (playersName == "Pejman")
		cout << endl << "\"Focus " << playersName << ", give this group a hundred percent.\"";
	else if (playersName == "Aaron")
		cout << endl << "Blaze it boiiis";
	else
		cout << endl << "\"Focus " << playersName << "\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	cout << endl << "*Footsteps in the distance getting closer*";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"Ok, I need to buy some time.\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"I know the C.I.A is coming for me.\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"They most likely, won't like it if I give to much information away.\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"I need to stall.\"";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	cout << endl << "**Door opens**";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "\"Shit.\"";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	system("pause");
	system("cls");
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	cout << "**Light turns on**";
	sleep_until(system_clock::now() + seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << endl << "Voice 1:\"...are almost near,";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << "        you need to get as much information as you can in the next few minutes..";
	sleep_until(system_clock::now() + seconds(2));
	cout << "        we won't have an opportunity like this again.\"";
	sleep_for(seconds(2));
	cout << endl << endl << "Voice 2:\"I understand sir.";
	sleep_until(system_clock::now() + seconds(2));
	cout << endl << endl << "Voice 1:\"Now wake him up and get to work.";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	cout << endl << endl << "**Door closes**";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << endl << "Voice 2:\"You better wake up from one bucket, becaue I don't have time";
	cout << endl << "        to get another";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	cout << endl << endl << "*SPLASH*";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player:\"Ugh, you pour another over me and i'll make sure you can never grab"
		<< endl << "       anything with that hand again.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << endl << "Voice 2:\"Ahhh You have a sense of humor?";
	sleep_for(seconds(2));
	cout << endl << "        Well that will only make the situation worse.\"";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player:\"And what situation is that?\"";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << endl << "Voice 2:\"The situation is that I ask the questions, not you.";
	sleep_for(seconds(2));
	cout << endl << "        So why are you here " << playersName << "?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	questionintro();
	//health loss here
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	sleep_for(seconds(2));
	cout << "Voice 2:\"Now let's try this again, were you with anyone else?" << endl;
	questionintro2();
	sleep_for(seconds(2));
	//respect gain here
	cout << "        Keep answering my questions cooperatively and this will go by fast and          easy.";
	sleep_for(seconds(2));
	cout << endl << "        But if you continue to be uncooperative,";
	sleep_for(seconds(2));
	cout << endl << "        this will be a very unpleasant experience for you..";
}

void punch()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "                                                                                "
		<< "                                 @@@@@@@,                                       "
		<< "                                @        @                                      "
		<< "                               @          @                                     "
		<< "                         @@@  @ ',    ,'   @                                    "
		<< "                       @'   ',@  @    @    @                                    "
		<< "                     @'        @           @                                    "
		<< "                   @'     .     @        @ @                                    "
		<< "                  @@@@@@ @ @     '@@@@@@'  @                                    "
		<< "                 @ / / /@  @      @         @                                   "
		<< "                 '@'@'@'@   @                @@@@                               "
		<< "                   *@@@@'    @                   @@@                            "
		<< "                             @                      @                           "
		<< "                             @               @      @                           "
		<< "                             @               @      @                           "
		<< "                              @               @      @                          "
		<< "                               @              @      @                          "
		<< "                               [''''@.@@@@@@@@@@     @                          "
		<< "                              [_                     @                          "
		<< "                              [_                     @                          "
		<< "                               {___,''@@@@@@@@@@@@@@@                           "
		<< "                               @                @                               "
		<< "                               @                @                               ";
	sleep_until(system_clock::now() + milliseconds(50));
	system("cls");
	cout << "                                                                                "
		<< "                                   @@@@@@                                       "
		<< "                                 @@      @@                                     "
		<< "                                @          @                                    "
		<< "                                @ ',    ,' @                                    "
		<< "                                @  @    @  @                                    "
		<< "                                @          @                                    "
		<< "                     @@@@@@@    '@        @                                     "
		<< "                   @@ , , , '@'@@ '@@@@@@' '@@@@                                "
		<< "                  @ @ @ @ @ , @                 @@@@                            "
		<< "                  @ | | | | @ @                     @@                          "
		<< "                   @'@'@'@'@@@                        @@                        "
		<< "                    *@@@@@@@' @               @         @@                      "
		<< "                               @               @@         ',                    "
		<< "                               @               @ @@        @                    "
		<< "                               @               @   @       @                    "
		<< "                               @               @   @       @                    "
		<< "                               @               @   @      @                     "
		<< "                               @               @    ,@    @                     "
		<< "                               @               @   :      :                     "
		<< "                               @               @   @      @                     "
		<< "                              @                 @  -'_'_'_                      "
		<< "                              @                 @                               ";
	sleep_until(system_clock::now() + milliseconds(50));
	system("cls");
	punchsound();
	cout << "                                                                                "
		<< "                                     @@@@@@                                     "
		<< "                                   @@      @@                                   "
		<< "                                  @          @                                  "
		<< "                                  @ ',    ,' @                                  "
		<< "                                  @  @    @  @                                  "
		<< "                                  @          @                                  "
		<< "                                  ,@        @                                   "
		<< "                              ,@@'  '@@@@@@' '@@@                               "
		<< "                             @                   @@                             "
		<< "                            @      @               @                            "
		<< "                           @        @              @                            "
		<< "                          @          @           @ @                            "
		<< "                          @          @           @ @                            "
		<< "                         @@-@@@-@@@@-@@          @  @                           "
		<< "                        @@            @@         @  @                           "
		<< "                       @   @   @   @    @       @   @                           "
		<< "                       @   @   @  @   @ @       @   @                           "
		<< "                        @   @  @  @   @ @       @   @                           "
		<< "                         @  @  @  @  @  @       @'@@                            "
		<< "                          '@'@@'@@'@@@  @      @                                "
		<< "                             '@@@@@@@@@'       @                                "
		<< "                               @               @                                ";
	system("cls");
	system("color f2");

	sleep_until(system_clock::now() + milliseconds(130));
	system("color 02");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "                                                                                "
		<< "                                   @@@@@@                                       "
		<< "                                 @@      @@                                     "
		<< "                                @          @                                    "
		<< "                                @ ',    ,' @                                    "
		<< "                                @  @    @  @                                    "
		<< "                                @          @                                    "
		<< "                     @@@@@@@    '@        @                                     "
		<< "                   @@ , , , '@'@@ '@@@@@@' '@@@@                                "
		<< "                  @ @ @ @ @ , @                 @@@@                            "
		<< "                  @ | | | | @ @                     @@                          "
		<< "                   @'@'@'@'@@@                        @@                        "
		<< "                    *@@@@@@@' @               @         @@                      "
		<< "                               @               @@         ',                    "
		<< "                               @               @ @@        @                    "
		<< "                               @               @   @       @                    "
		<< "                               @               @   @       @                    "
		<< "                               @               @   @      @                     "
		<< "                               @               @    ,@    @                     "
		<< "                               @               @   :      :                     "
		<< "                               @               @   @      @                     "
		<< "                              @                 @  -'_'_'_                      "
		<< "                              @                 @                               " << endl;
	music();
	system("cls");
}

void timer()
{
	int m, s, h;
	/* << "A COUNTDOWN TIMER " << endl;
	cout << "enter time in hours here" << endl;
	cin >> h;
	cout << "enter time in minutes here " << endl;
	cin >> m;
	cout << "enter im in seconds here" << endl;
	cin >> s;
	cout << "Press any key to start" << endl;
	cout << " A COUNTDOWN TIMER" << endl;
	cout << "time remaining" << endl;*/
	h = 0;
	m = 5;
	s = 0;
	cout << "hours : " << h << "mins : " << m << " secs : " << s << endl;
	for (int hour = h; hour >= 0; hour--)
	{
		for (int min = m; min >= 0; min--)
		{
			if (min == 0 && h > 0)
				m = 59;
			for (int sec = s; sec >= 0; sec--)
			{
				if (sec == 0)
					s = 59;
				Sleep(1000);
				system("cls");
				cout << hour << " :hours " << min << " :mins " << sec << " :secs" << endl;
			}
		}
	}

	Sleep(1000);
	cout << "THE END" << endl;
}

void questionintro()
{
	int B;
	cout << endl << endl << "Player: 1) I was looking for your wife, must have taken a wrong turn" << endl;
	cout << "        2) I must have taken a wrong turn, can you point me in the direction of             your mother?";
	cout << endl;
	cin >> B;
	if (B == 1) {
		punch();
	}
	else if (B == 2){
		punch();
	}
	else
	{
		punch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		questionintro();
	}
	B = 0;
}

void questionintro2()
{
	int C;
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << "Player: 1) Not that I can remember." << endl;
	cout << "        2) Not that I can remember.";
	cout << endl;
	cin >> C;
	if (C == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"That's a better answer." << endl;
	}
	else if (C == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"That's a better answer." << endl;
	}
	else
	{
		punch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		questionintro2();
	}
	C = 0;
}

void questions()
{
	question1();
}

void question1()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "        Now. Who do you work for.";
	sleep_for(seconds(2));
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	cout << " HEALTH BAR: ";
	healthbar();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	cout << "RESPECT BAR: ";
	respectbar();
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << "Player: 1) State Farm" << endl;
	cout << "        2) FBI (Female Body Inspector)" << endl;
	cout << "        3) C.I.A" << endl;
	cin >> A;
	if (A == 1)
	{
		punch();
		sleep_for(seconds(2));
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question2();
		//lose health
	}
	else if (A == 2)
	{
		punch();
		sleep_for(seconds(2));
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question2();
		//lose health
	}
	else if (A == 3)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"Hmm...Very interesting." << endl << endl;
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question2();
	}
	else
	{
		littlebitch();
	}
}

void question2()
{

	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"Why are you here.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) To make pancakes." << endl;
	cout << "        2) To retrieve information." << endl;
	cout << "        3) To blow you bastards up!" << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question5();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question3();
	}
	else if (A == 3)
	{
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question6();
	}
	else
	{
		littlebitch();
	}

}

void question3()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"What information?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Phone numbers, bank accounts, the usual." << endl;
	cout << "        2) Your internet explorer history." << endl;
	cout << "        3) The Death Star plans." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question4();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"We use Chrome you twat. You know that.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(2));
		question4();
	}
	else if (A == 3)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"Those aren't in our computers.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(2));
		question4();
	}
	else
	{
		littlebitch();
	}
}

void question4()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: And the bombs you planted?\"";
	int A;
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Shit you found those eh?" << endl;
	cout << "        2) What bombs." << endl;
	cout << "        3) Yea I set a few fireworks around." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question9();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question9();
	}
	else if (A == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question9();
	}
	else
	{
		littlebitch();
	}

}

void question5()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "Voice 2:\"I hope you got your pancakes.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Yeah but they needed more maple syrup." << endl;
	cout << "        2) No, but I got me some nice information." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\" Wise guy.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question6();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		question3();
	}
	else
	{
		littlebitch();
	}
}

void question6()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "Voice 2:\"Who helped you get pass security?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) My daughter's 3rd grade teacher." << endl;
	cout << "        2) Somebody from inside your organisation." << endl;
	cout << "        3) My asshole supervisor." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"We let her go a long time ago. She no longer works here.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question8();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << endl << "Voice 2:\"You're lying.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question7();
	}
	else if (A == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << "Voice 2:\"Not as bad as mine.\"" << endl << endl;
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question4();
	}
	else
	{
		littlebitch();
	}
}

void question7()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "Voice 2:\"You're lying. Don't lie to me!\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Yeah I am." << endl;
	cout << "        2) For your sake, I wish I was." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(1));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << "Voice 2:\"Don't you dare lie to me again.\"";
		question4();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(1));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << "Voice 2:\"Shut up.\"";
		question4();
	}
	else
	{
		littlebitch();
	}
}

void question8()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"Speaking of your daughter, wouldn't it be a shame if something were to happen to her?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Talk about her again and I'll smash your head with that bucket." << endl;
	cout << "        2) Look, I'll tell you whatever you need to know, just leaver her               out of this." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(1));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		question4();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(1));
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		question9();
	}
	else
	{
		littlebitch();
	}
}

void question9()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"How many did you plant?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) I was never good at geography." << endl;
	cout << "        2) Four." << endl;
	cout << "        3) 1 + 1....shit..I lost count..." << endl;
	cin >> A;
	if (A == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question10();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question10();
	}
	else if (A == 3)
	{
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question10();
	}
	else
	{
		littlebitch();
	}
}

void question10()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"What went wrong. Why were you caught?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: \"What are you talking about.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << endl << "Voice 2: \"By the C.I.A. Why were you caught!\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) I did nothing wrong! Somebody set me up! (Play Aggressive)" << endl;
	cout << "        2) Someone must have seen me plant the explosives. (Play Dumb)" << endl;
	
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question11();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question15();
	}
	else
	{
		littlebitch();
	}
}

void question11()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"What do you mean you were set up.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Someone wanted me gone. Someone from within." << endl;
	cout << "        2) I mean, could've been you for all I know, asswipe." << endl;

	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question12();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << "Voice 2:\"Ha. Very funny.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question12();
	}
	else
	{
		littlebitch();
	}
}

void question12()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"And who do you think would do such a thing?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Already told you dipshit. I bet it's you." << endl;
	cout << "        2) Probably the guy ranked under me in the organisation." << endl;

	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		punch();
		damage = true;
		respectdamage = true;
		cout << endl << endl << "Voice 2: \"Why do you think that?\"";
		sleep_for(seconds(3));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		cout << endl << endl << "Player: \"Why else would you be interested in my capture? Hmm?";
		sleep_for(seconds(3));
		cout << endl << "        Instead of information when you have limited time?\"" << endl;
		sleep_for(seconds(3));
		punch();
		cout << "Voice 2: \"I said I ask the questions.\"" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question14();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2: \"Why do you think that?\"";
		sleep_for(seconds(3));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		cout << endl << endl << "Player: \"Everyone was always living in my shadow\"" << endl << endl;
		sleep_for(seconds(3));
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(2));
		question13();
	}
	else
	{
		littlebitch();
	}
}

void question13()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"You got that right.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Huh?" << endl;
	cout << "        2) Well, no shit sherlock, I was the best." << endl;

	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		aggresiveending();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(2));
		punch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		damage = true;
		respectdamage = true;
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		aggresiveending();
	}
	else
	{
		littlebitch();
	}
}

void question14()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"Did you really think you would be Number 1 forever?.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Huh?" << endl;
	cout << "        2) Hell Yeah, I was the best." << endl;

	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		aggresiveending();
	}
	else if (A == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		sleep_for(seconds(2));
		punch();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		damage = true;
		respectdamage = true;
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		aggresiveending();
	}
	else
	{
		littlebitch();
	}
}

void question15()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"For a #1 terrorist, you aren't that sneaky.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) I'm not a terrorist anymore." << endl;
	cout << "        2) But I was still #1." << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2: \"You're right about that.\"" << endl << endl;
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question16();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << "Voice 2:\"Not anymore.\"";
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question16();
	}
	else
	{
		littlebitch();
	}
}

void question16()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"You were good, but not loyal.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) There is no such thing as loyalty in our line of work." << endl;
	cout << "        2) Loyal? It was someone within the organisation that betrayed me." << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		gain = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question17();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"Don't make accusations without any proof.\"";
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		cout << endl << endl << "Player: I don't need proof, I just need a name." << endl;
		sleep_for(seconds(2));
		question19();
	}
	else
	{
		littlebitch();
	}
}

void question17()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"Oh is that true?\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) Why do you think I traded sides." << endl;
	cout << "        2) Loyalty will just get you killed." << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		punch();
		damage = true;
		respectdamage = true;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		cout << " HEALTH BAR: ";
		healthbar();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
		cout << "RESPECT BAR: ";
		respectbar();
		sleep_for(seconds(1));
		question18();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2:\"So does betrayal.";
		sleep_for(seconds(3));
		cout << endl << "        Luckily, I remain loyal.\"";
		sleep_for(seconds(3));
		gun();
	}
	else
	{
		littlebitch();
	}
}

void question18()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"You became a traitor once you got caught.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) I did what I thought was right!" << endl;
	cout << "        2) I did what I had to do." << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2: \"Well, you were wrong.\"";
		sleep_for(seconds(2));
		gun();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		cout << endl << "Voice 2: \"That's funny, because I'm going to tsay the same thing.\"";
		sleep_for(seconds(2));
		gun();
	}
	else
	{
		littlebitch();
	}
}

void question19()
{
	int A;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2: \"Who's name.\"";
	sleep_for(seconds(2));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	cout << endl << endl << "Player: 1) The little bitch infront of me" << endl;
	cout << "        2) The asshole that set me up." << endl;
	cin >> A;
	if (A == 1)
	{
		sleep_for(seconds(2));
		gun();
	}
	else if (A == 2)
	{
		sleep_for(seconds(2));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		punch();
		sleep_for(seconds(2));
		cout << endl << "Voice 2: \"I should have just killed you sooner.\"";
		sleep_for(seconds(2));
		ending(); 
	}
	else
	{
		littlebitch();
	}
}

void healthbar()
{
	if (health == 100 && damage == false)
	{
		cout << health << " [][][][][][][][][][]";
	}
	else if (damage == true)
	{
		health = (health - (7 * damagemodifier));
		damage = false;
		if (health <= 100 && health >= 95)
		{
			cout << health << "  [][][][][][][][][][";
		}
		else if (health <= 95 && health >= 90)
		{
			cout << health << "  [][][][][][][][][]";
		}
		else if (health <= 90 && health >= 85)
		{
			cout << health << "  [][][][][][][][][";
		}
		else if (health <= 85 && health >= 80)
		{
			cout << health << "  [][][][][][][][]";
		}
		else if (health <= 80 && health >= 75)
		{
			cout << health << "  [][][][][][][][";
		}
		else if (health <= 75 && health >= 70)
		{
			cout << health << "  [][][][][][][]";
		}
		else if (health <= 70 && health >= 65)
		{
			cout << health << "  [][][][][][][";
		}
		else if (health <= 65 && health >= 60)
		{
			cout << health << "  [][][][][][]";
		}
		else if (health <= 60 && health >= 55)
		{
			cout << health << "  [][][][][][";
		}
		else if (health <= 55 && health >= 50)
		{
			cout << health << "  [][][][][]";
		}
		else if (health <= 50 && health >= 45)
		{
			cout << health << "  [][][][][";
		}
		else if (health <= 45 && health >= 40)
		{
			cout << health << "  [][][][]";
		}
		else if (health <= 40 && health >= 35)
		{
			cout << health << "  [][][][";
		}
		else if (health <= 35 && health >= 30)
		{
			cout << health << "  [][][]";
		}
		else if (health <= 30 && health >= 25)
		{
			cout << health << "  [][][";
		}
		else if (health <= 25 && health >= 20)
		{
			cout << health << "  [][]";
		}
		else if (health <= 20 && health >= 15)
		{
			cout << health << "  [][";
		}
		else if (health <= 15 && health >= 10)
		{
			cout << health << "  []";
		}
		else if (health <= 10 && health >= 5)
		{
			cout << health << "  [";
		}
		else if (health <= 5 && health >= 0)
		{
			cout << health << "  [";
		}
		else if (health <= 0)
		{
			gun();
		}
	}
	else if (damage == false)
	{
		if (health <= 100 && health >= 95)
		{
			cout << health << "  [][][][][][][][][][";
		}
		else if (health <= 95 && health >= 90)
		{
			cout << health << "  [][][][][][][][][]";
		}
		else if (health <= 90 && health >= 85)
		{
			cout << health << "  [][][][][][][][][";
		}
		else if (health <= 85 && health >= 80)
		{
			cout << health << "  [][][][][][][][]";
		}
		else if (health <= 80 && health >= 75)
		{
			cout << health << "  [][][][][][][][";
		}
		else if (health <= 75 && health >= 70)
		{
			cout << health << "  [][][][][][][]";
		}
		else if (health <= 70 && health >= 65)
		{
			cout << health << "  [][][][][][][";
		}
		else if (health <= 65 && health >= 60)
		{
			cout << health << "  [][][][][][]";
		}
		else if (health <= 60 && health >= 55)
		{
			cout << health << "  [][][][][][";
		}
		else if (health <= 55 && health >= 50)
		{
			cout << health << "  [][][][][]";
		}
		else if (health <= 50 && health >= 45)
		{
			cout << health << "  [][][][][";
		}
		else if (health <= 45 && health >= 40)
		{
			cout << health << "  [][][][]";
		}
		else if (health <= 40 && health >= 35)
		{
			cout << health << "  [][][][";
		}
		else if (health <= 35 && health >= 30)
		{
			cout << health << "  [][][]";
		}
		else if (health <= 30 && health >= 25)
		{
			cout << health << "  [][][";
		}
		else if (health <= 25 && health >= 20)
		{
			cout << health << "  [][]";
		}
		else if (health <= 20 && health >= 15)
		{
			cout << health << "  [][";
		}
		else if (health <= 15 && health >= 10)
		{
			cout << health << "  []";
		}
		else if (health <= 10 && health >= 5)
		{
			cout << health << "  [";
		}
		else if (health <= 5 && health >= 0)
		{
			cout << health << "  [";
		}
		else if (health <= 0)
		{
			gun();
		}
		
	}
	cout << endl;
};

void respectbar()
{
	if (respect == 100 && respectdamage == false)
	{
		cout << respect << " [][][][][][][][][][]";
	}
	else if (respectdamage == true)
	{
		respect = (respect - 10);
		respectdamage = false;
		if (respect <= 99 && respect >= 90)
		{
			damagemodifier = 2;
			cout << respect << "  [][][][][][][][][]";
		}
		else if (respect <= 90 && respect >= 80)
		{
			damagemodifier = 4;
			cout << respect << "  [][][][][][][][]";
		}
		else if (respect <= 80 && respect >= 70)
		{
			damagemodifier = 6;
			cout << respect << "  [][][][][][][]";
		}
		else if (respect <= 70 && respect >= 60)
		{
			damagemodifier = 8;
			cout << respect << "  [][][][][][]";
		}
		else if (respect <= 60 && respect >= 50)
		{
			damagemodifier = 10;
			cout << respect << "  [][][][][]";
		}
		else if (respect <= 50 && respect >= 40)
		{
			damagemodifier = 12;
			cout << respect << "  [][][][]";
		}
		else if (respect <= 40 && respect >= 30)
		{
			damagemodifier = 14;
			cout << respect << "  [][][]";
		}
		else if (respect <= 30 && respect >= 20)
		{
			damagemodifier = 16;
			cout << respect << "  [][]";
		}
		else if (respect <= 20 && respect >= 10)
		{
			damagemodifier = 18;
			cout << respect << "  []";
		}
		else if (respect <= 10 && respect >= 0)
		{
			damagemodifier = 20;
			cout << respect << " ";
		}
	}
	else if (gain == true)
	{
		respect = (respect + 10);
		gain = false;
		if (respect == 100)
		{
			cout << respect << " [][][][][][][][][][]";
		}
		if (respect <= 99 && respect >= 90)
		{
			damagemodifier = 2;
			cout << respect << "  [][][][][][][][][]";
		}
		else if (respect <= 90 && respect >= 80)
		{
			damagemodifier = 3;
			cout << respect << "  [][][][][][][][]";
		}
		else if (respect <= 80 && respect >= 70)
		{
			damagemodifier = 4;
			cout << respect << "  [][][][][][][]";
		}
		else if (respect <= 70 && respect >= 60)
		{
			damagemodifier = 5;
			cout << respect << "  [][][][][][]";
		}
		else if (respect <= 60 && respect >= 50)
		{
			damagemodifier = 6;
			cout << respect << "  [][][][][]";
		}
		else if (respect <= 50 && respect >= 40)
		{
			damagemodifier = 7;
			cout << respect << "  [][][][]";
		}
		else if (respect <= 40 && respect >= 30)
		{
			damagemodifier = 8;
			cout << respect << "  [][][]";
		}
		else if (respect <= 30 && respect >= 20)
		{
			damagemodifier = 9;
			cout << respect << "  [][]";
		}
		else if (respect <= 20 && respect >= 10)
		{
			damagemodifier = 10;
			cout << respect << "  []";
		}
		else if (respect <= 10 && respect >= 0)
		{
			damagemodifier = 11;
			cout << respect << " ";
		}
	}
	cout << endl;
};

int punchsound()
{
	PlaySound(TEXT("Punch.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

int music()
{
	PlaySound(TEXT("ThisHouse.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	return 0;
}

int gunshot()
{
	PlaySound(TEXT("GUN_FIRE.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

void gun()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "                                                                                "
		<< "                                      ,@@@@@@@                                  "
		<< "                                     @        '@                                "
		<< "                      @@@           @           @                               "
		<< "                    @@  @*         @',   ,'      @                              "
		<< "                    @   @          @ @   @       @                              "
		<< "                     @  @          @             @                              "
		<< "                     @   @          @           @                               "
		<< "                    (@  ,&           '@@@@@'   @                                "
		<< "                   ( @  ;@@@       @@@          @@@@                            "
		<< "                ;@@@@@ @    @    @@                 @                           "
		<< "                ;@@@@@@@@    @ @@        @@         @                           "
		<< "                  @    @'@    @        @@          @                            "
		<< "                   @  @   @    @   , @@          @@@                            "
		<< "                   @   @  @     @,'@@          @@  @                            "
		<< "                    @   @' @     @@         @@@    @                            "
		<< "                    @    @  @           @@@@      @                             "
		<< "                     @       @@      @@@          @                             "
		<< "                      @    @'  @@@@@@             @                             "
		<< "                       @@@@      @                @                             "
		<< "                                 @                @                             "
		<< "                                 @               @                              "
		<< "                                 @               @                              "
		<< "                                  @              @                              "
		<< "                                  @              @                              ";
	sleep_until(system_clock::now() + milliseconds(100));
	system("cls");
	cout << "                                                                                "
		<< "                                         @@@@@@@                                "
		<< "                                       @         @                              "
		<< "                                      @           @                             "
		<< "                                     @ ',    ,'    @                            "
		<< "                                     @  @    @     @                            "
		<< "                           @@        @             @                            "
		<< "                          @ ,@        @           @                             "
		<< "                          @@  @         @@@@@@    @                             "
		<< "                           @   @      @@'          @@@                          "
		<< "                            @   @    @                @@                        "
		<< "                             @(  @  @                   @                       "
		<< "                            @  @@ @'  ,                 @                       "
		<< "                             @@   @   @          @       @                      "
		<< "                               @   @  @          @       @                      "
		<< "                               @    ' @           @       @                     "
		<< "                                @     @ @@,,@@@@@@@       @                     "
		<< "                                 @   @:@                  @                     "
		<< "                                  @@@ @ @@,,@@@@@@@@@@@@@@                      "
		<< "                                      @               @                         "
		<< "                                      @               @                         "
		<< "                                      @               @                         "
		<< "                                       @              @                         "
		<< "                                       @              @                         "
		<< "                                       @              @                         ";

	sleep_until(system_clock::now() + milliseconds(100));
	system("cls");
	cout << "                                                                                "
		<< "                                         ,@@@@@@,                               "
		<< "                                        @        @                              "
		<< "                                       ;          ;                             "
		<< "                                      @  ',    ,'  @                            "
		<< "                                      @   @    @   @                            "
		<< "                                      @            @                            "
		<< "                                       '@,      ,@'                             "
		<< "                                          @@@@@@                                "
		<< "                                   ,, @@@'      '@@@@@,                         "
		<< "                                 @@@@@@                @                        "
		<< "                                 @ ,, @                @                        "
		<< "                                 @ '' @                 @                       "
		<< "                                 $    $              @  @                       "
		<< "                                 @@''@@              @   @                      "
		<< "                                 @----@              @   @                      "
		<< "                                 @---@               @    @                     "
		<< "                                  @_@               @ @   @                     "
		<< "                                     @              @  @  @                     "
		<< "                                     @              @  @  @                     "
		<< "                                     @              @ @    @                    "
		<< "                                     @              @  @@@@                     "
		<< "                                    @               @                           "
		<< "                                    @               @                           "
		<< "                                    @               @                           " << endl;
	sleep_until(system_clock::now() + milliseconds(200));
	gunshot();
	system("cls");
	sleep_until(system_clock::now() + milliseconds(100));
	system("color C2");
	sleep_until(system_clock::now() + milliseconds(2000));
	music();
	system("color 02");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color C2");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color 02");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color C2");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color 02");
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	cout << "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                    GAME OVER                                   "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                ";
	system("pause");
	system("cls");
	credits();
	main();
}

void littlebitch()
{
	for (int i = 0; i < 5; i++)
	{
		punch();
	}
	gun();
}

void ending()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << "                                                                                "
		<< "                                      ,@@@@@@@                                  "
		<< "                                     @        '@                                "
		<< "                      @@@           @           @                               "
		<< "                    @@  @*         @',   ,'      @                              "
		<< "                    @   @          @ @   @       @                              "
		<< "                     @  @          @             @                              "
		<< "                     @   @          @           @                               "
		<< "                    (@  ,&           '@@@@@'   @                                "
		<< "                   ( @  ;@@@       @@@          @@@@                            "
		<< "                ;@@@@@ @    @    @@                 @                           "
		<< "                ;@@@@@@@@    @ @@        @@         @                           "
		<< "                  @    @'@    @        @@          @                            "
		<< "                   @  @   @    @   , @@          @@@                            "
		<< "                   @   @  @     @,'@@          @@  @                            "
		<< "                    @   @' @     @@         @@@    @                            "
		<< "                    @    @  @           @@@@      @                             "
		<< "                     @       @@      @@@          @                             "
		<< "                      @    @'  @@@@@@             @                             "
		<< "                       @@@@      @                @                             "
		<< "                                 @                @                             "
		<< "                                 @               @                              "
		<< "                                 @               @                              "
		<< "                                  @              @                              "
		<< "                                  @              @                              ";
	sleep_until(system_clock::now() + milliseconds(100));
	system("cls");
	cout << "                                                                                "
		<< "                                         @@@@@@@                                "
		<< "                                       @         @                              "
		<< "                                      @           @                             "
		<< "                                     @ ',    ,'    @                            "
		<< "                                     @  @    @     @                            "
		<< "                           @@        @             @                            "
		<< "                          @ ,@        @           @                             "
		<< "                          @@  @         @@@@@@    @                             "
		<< "                           @   @      @@'          @@@                          "
		<< "                            @   @    @                @@                        "
		<< "                             @(  @  @                   @                       "
		<< "                            @  @@ @'  ,                 @                       "
		<< "                             @@   @   @          @       @                      "
		<< "                               @   @  @          @       @                      "
		<< "                               @    ' @           @       @                     "
		<< "                                @     @ @@,,@@@@@@@       @                     "
		<< "                                 @   @:@                  @                     "
		<< "                                  @@@ @ @@,,@@@@@@@@@@@@@@                      "
		<< "                                      @               @                         "
		<< "                                      @               @                         "
		<< "                                      @               @                         "
		<< "                                       @              @                         "
		<< "                                       @              @                         "
		<< "                                       @              @                         ";

	sleep_until(system_clock::now() + milliseconds(100));
	system("cls");
	cout << "                                                                                "
		<< "                                         ,@@@@@@,                               "
		<< "                                        @        @                              "
		<< "                                       ;          ;                             "
		<< "                                      @  ',    ,'  @                            "
		<< "                                      @   @    @   @                            "
		<< "                                      @            @                            "
		<< "                                       '@,      ,@'                             "
		<< "                                          @@@@@@                                "
		<< "                                   ,, @@@'      '@@@@@,                         "
		<< "                                 @@@@@@                @                        "
		<< "                                 @ ,, @                @                        "
		<< "                                 @ '' @                 @                       "
		<< "                                 $    $              @  @                       "
		<< "                                 @@''@@              @   @                      "
		<< "                                 @----@              @   @                      "
		<< "                                 @---@               @    @                     "
		<< "                                  @_@               @ @   @                     "
		<< "                                     @              @  @  @                     "
		<< "                                     @              @  @  @                     "
		<< "                                     @              @ @    @                    "
		<< "                                     @              @  @@@@                     "
		<< "                                    @               @                           "
		<< "                                    @               @                           "
		<< "                                    @               @                           " << endl;
	sleep_until(system_clock::now() + milliseconds(150));
	system("cls");
	cout
		<< "                                                                                "
		<< "                                         ,@@@@@@,                               "
		<< "                                        @        @                              "
		<< "                                       ;          ;                             "
		<< "                                      @  ',    ,'  @==========                  "
		<< "                                      @   @    @   @          ||                "
		<< "                                      @            @          ||                "
		<< "                                      |'@,       ,@'          ||                "
		<< "                                      ||  @@@@@@@             ||                "
		<< "                                   ,, @@@'       '@@@@@,      ||                "
		<< "                                 @@@@@@                 @     ||                "
		<< "                                 @ ,, @                 @     ||                "
		<< "                                 @ '' @                  @    ||                "
		<< "                                 $    $               @  @    ||                "
		<< "                                 @@''@@               @   @   ||                "
		<< "                                 @----@               @   @   ||                "
		<< "                                 @---@                @    @  ||                "
		<< "                                  @_@                @ @   @  ||                "
		<< "                                     @               @  @  @  ||                "
		<< "                                     @               @  @  @  ||                "
		<< "                                     @               @ @    @ ||                "
		<< "                                     @               @ &@@@@  ||                "
		<< "                                    @                @ &      ||                "
		<< "                                    @                @ &      ||                "
		<< "                                    @                @ &      ||                "
		<< "                                                                                " << endl;
	sleep_until(system_clock::now() + milliseconds(250));
	gunshot();
	system("cls");
	cout
		<< "                                                                                "
		<< "                                    ,@@@@@@,                                    "
		<< "                                   @        @                                   "
		<< "                                  ;          ;                                  "
		<< "                                 @  ',    ,'  @===============                  "
		<< "                                 @   @    @   @               ||                "
		<< "                                 @            @               ||                "
		<< "                                  '@,      ,@'                ||                "
		<< "                                     @@@@@@                   ||                "
		<< "                              ,, @@@'      '@@@@@,            ||                "
		<< "                            @@@@@@                @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "         ||                "
		<< "                            @ ,, @                @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                            @ '' @         "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << "@"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                            $    $              @  @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                            @@''@@              @   @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << ","; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                            @----@              @   @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "'&&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    ||                "
		<< "                            @---@               @    @   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    ||                "
		<< "                             @_@               @ @   @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "     ||                "
		<< "                                @              @  @  @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                "
		<< "                                @              @  @  @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                                @              @ @    @       ||                "
		<< "                                @              @  @@@@"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                               @               @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                               @               @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                               @               @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                                                                                " << endl;
	sleep_until(system_clock::now() + milliseconds(250));
	system("cls");
	cout
		<< "                                                                                "
		<< "                               ,@@@@@@,                                         "
		<< "                              @        @                                        "
		<< "                             ;          ;                                       "
		<< "                            @            @====================                  "
		<< "                            @   ,-    -, @                    ||                "
		<< "                            @    @    @  @                    ||                "
		<< "                              @        @                      ||                "
		<< "                               '@@@@@@'                       ||                "
		<< "                           @@@@        @@@@@                  ||                "
		<< "                         @@                  @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << ",&&&&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "         ||                "
		<< "                        @                    @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                        @             "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << "@"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                        @   @         "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << ";"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    @  @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                        @   @              @   @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&&&&',"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                "
		<< "                        @   @              @   @      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "'&&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    ||                "
		<< "                       @  @ @              @    @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "___&    &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    ||                "
		<< "                      @    @              @ @   @       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "     ||                "
		<< "                      @@   @              @  @  @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "==&&&&&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                "
		<< "                        @@ @              @  @  @     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                           @              @ @    @    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                           @              @  @@@@     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                          @               @    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                          @               @    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                          @               @   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&       &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                "
		<< "                                                                                " << endl;
	sleep_until(system_clock::now() + milliseconds(250));
	gunshot();
	system("cls");
	cout
		<< "                                                                                "
		<< "                          ,@@@@@@,                                              "
		<< "                         @        @                                             "
		<< "                        ;          ;                                            "
		<< "                       @            @  =======================                  "
		<< "                       @            @ ||                     ||                 "
		<< "                       @    ,-   -, @ ||                     ||                 "
		<< "                         @   @   @@   ||                     ||                 "
		<< "                          '@@@@@@'    ||                     ||                 "
		<< "                      @@@@'       @@@@@|       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << ",&&&&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "        ||                 "
		<< "                    @@                  @     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                 "
		<< "                   @                    @     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                 "
		<< "                   @             "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << "@"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       @    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                 "
		<< "                   @   @         "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << "| @"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "  @  @     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "'&&&&',"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "       ||                 "
		<< "                   @   @         "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C); cout << "; ;"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "  @   @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "[]'      '&&,"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "   ||                 "
		<< "                   @   @              @   @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&&&____&    &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "   ||                 "
		<< "                   @   @              @    @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&          &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "    ||                 "
		<< "                   @   @             @ @   @ "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "'&&===&&&&&"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "     ||                 "
		<< "                  @   @              @||@  @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&       &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                  @   @              @||@  @   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                   @@@               @|@    @  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                      @              @||@@@@   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                     @               @||       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                     @               @||       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&      &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                     @               @||      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01); cout << "&       &"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); cout << "      ||                 "
		<< "                                                                                " << endl;
	sleep_until(system_clock::now() + milliseconds(200));
	gunshot();
	system("cls");
	sleep_until(system_clock::now() + milliseconds(100));
	system("color A2");
	sleep_until(system_clock::now() + milliseconds(2000));
	music();
	system("color 02");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color A2");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color 02");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color A2");
	sleep_until(system_clock::now() + milliseconds(50));
	system("color 02");
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
	cout << "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "   @@@   ,@                @@                ,@'@,                         @@   "
		<< "   @@@  @@   ,@@@,  ,@@  ,  ' ,@@   ,@,     ,@@, '   ,'@, ,@  ,,  ,@,   ,,@@'   "
		<< "    @@,@@   @@   @@ @@ ,@@    @ '',@ ,@       '@@  @@  @@ @@ ,@ ,@ ,@ ,@  @@    "
		<< "    '@@@    '@',@@ '@@''@@   '@   '@@,,    '@@,@' '@@@'@@ '@@'  '@@,, @@,'@@    "
		<< "  @@@@                                                                          "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                "
		<< "                                                                                ";
	system("pause");
	system("cls");
	credits();
	
	main();
}

void aggresiveending()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << endl << "Voice 2:\"Ever since you came, it's been complete crap for me.";
		sleep_for(seconds(2));
		cout << endl << "        Being #2? That shit sucks. More so when it used to be the other way" << endl << "        around.";
		sleep_for(seconds(2));
		cout << endl << "        Then one day I said that's Enough. You were supposed to be out of" << endl << "        the picture....\"";
		sleep_for(seconds(2));
		ending();
}

int introstory()
{
	string message = "You used to be a terrorist. A damn good terrorist.\n"
		"But now you work for the CIA.\n"
		"This certain situation came to be after you mistimed your entry on one of your\n"
		"planned acts of terrorism. You walked into Madison Square Garden ready to set \n"
		"your explosives but what you meet is a welcome party of 50 CIA agents.\n"
		"To this day you don't know the man that tipped the CIA off. \n"
		"But you know that it was from your terrorist group. Once you had \n"
		"been taken into CIA headquarters, they gave you a proposition, \n"
		"to either go to prison for life, or to work for the CIA.\n"
		"If you chose to work for the CIA you would have to infiltrate your own terrorist"
		"organisation in order to bring them down. You chose this, because you knew that "
		"you would then also be able to get revenge against the man that ratted you out. "
		"The preparations are made and you are sent back to the kamikaze's headquarters. "
		"Your mission is to infiltrate the hideout and try and kill the ones in charge \n"
		"while simultaneously setting up explosives around the complex. \n"
		"Just like you had to do when you were caught by the CIA.\n";
	slow_print(message, 15);
	cout << endl << endl;
	system("pause");

	return 0;
}

void slow_print(const string& message, unsigned int millis_per_char)
{
	// Range loops are "for each" constructs; here: for each character in the string
	for (const char c : message)
	{
		// flush is used to make sure the buffer is emptied to the terminal immediately
		cout << c << flush;

		// Ask the thread to sleep for at least n millis.
		sleep_for(milliseconds(millis_per_char));
	}
}

void credits()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	sleep_for(seconds(2));
	cout << "                                                                                "
		 << "                                    Credits                                     "
		 << "                                                                                "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	sleep_for(seconds(2));
	cout << "                            Production Manager/Story                            "
		 << "                                   Ryan Hovan                                   "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
	sleep_for(seconds(2));
	cout << "                                                                                "
	 	 << "                          Game Design/Story/Programming                         "
	 	 << "                                  Talib Rashdi                                  "
	 	 << "                                                                                "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
	sleep_for(seconds(2));
	cout << "                                   Programming                                  "
		 << "                                  Doug Campbell                                 "
		 << "                                                                                "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
	sleep_for(seconds(2));
	cout << "                                   Programming                                  "
		 << "                                  Gregg Campbell                                "
		 << "                                                                                "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
	sleep_for(seconds(2));
	cout << "                                       Art                                      "
		 << "                                   Anson Cheng                                  "
		 << "                                                                                "
		 << "                                                                                ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	sleep_for(seconds(2));
	cout << "                                 Special Thanks                                 "
		 << "                                   Aaron Baker                                  ";
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	system("pause");
	system("cls");
}