#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*Hopefully, a working ROV simulator!
 *Use w,a,s,d to controll your ROV!
 *You are moving throughout a 10 x 10 grid and picking up items
 *Use z to pick up an item and x to drop it!
 */


class Rov //ROV class, used to create item inventory
{
private:
    vector<string> itemVector;
public:
    Rov(string item);
    ~Rov();

    string getItem (int index);

    void addItem (string item);

    string showItem (int index);

};

Rov::Rov(string item) //Constructor
{
    if (!item.empty())
    {
        itemVector.push_back(item);
    }
}
Rov::~Rov() //Destructor
{
}

string Rov::getItem(int index) //Erases item from inventory
{
    string item;
    if (index >= itemVector.size()) //Checks if item can be erased
    {
        cout << "No item here to erase!" << endl;
    }
    else
    {
        itemVector[index];
        item = itemVector[index];
        itemVector.erase(itemVector.begin()+index);
    }
    return item;
}

void Rov::addItem(string item) //Adds an item to inventory
{
    itemVector.push_back(item);
}
string Rov::showItem(int index) //Displays one item from the inventory
{
    string item;
    if (index >= itemVector.size()) //CHecks if item exists
    {
        cout << "[" << index << "] empty slot" << endl;
    }
    else
    {
        itemVector[index];
        item = itemVector[index];
        cout << "[" << index << "] " << item << endl;
    }
    return item;
}

int changePosition() //This is the function to change the position!
{
    char p;
    int x = 1; //These are the item position coordinates!
    int y = 1;
    int xa = 2; //These are the preset coordinates for each item
    int ya = 7;
    int xb = 6;
    int yb = 5;
    int xc = 9;
    int yc = 9;
    Rov item1("item1"); //Declaration of item (it exists!)
    cout << "Try and find the three(3) items on this map!" << endl; //Starting comments
    cout << "Starting Position: (1, 1)" << endl;
    cout << " __________________________" << endl;
    cout << "| Controls:                |" << endl;
    cout << "| movement - w,a,s,d       |" << endl;
    cout << "| item pickup/drop - z/x   |" << endl;
    cout << "| end game/back - b        |" << endl;
    cout << "|__________________________|" << endl;
    while (y < 12)
    {
        cout << "Where do you want to move?" << endl;
        cin >> p;
        if (p == 'w') //Updates position
        {
            y = y + 1;
        }
            else if (p == 'a')
            {
                x = x - 1;
            }
            else if (p == 's')
            {
                y = y - 1;
            }
            else if (p == 'd')
            {
                x = x + 1;
            }
            else if (p == 'x') //Call to drop item
            {
                char choice;
                cout << "_____________________________________________" << endl;
                item1.showItem(1);
                item1.showItem(2);
                item1.showItem(3);
                cout << "_____________________________________________" << endl;
                cout << "which item would you like to drop?" << endl;
                cin >> choice;
                if (choice == '1')
                {
                    item1.getItem(1); //Erases item
                    xa = x;           //Updates item positon to current position
                    ya = y;
                }
                if (choice == '2')
                {
                    item1.getItem(2);
                    xb = x;
                    yb = y;
                }
                if (choice == '3')
                {
                    item1.getItem(3);
                    xc = x;
                    yc = y;
                }
            }
            else if (p == 'b') //Ends game
            {
                y = 12;
                cout << "Goodbye!" << endl;
                return 0;
            }
        if (y > 10) //Movement Restrictions
        {
            cout << "You can't go there! What do you think this is, an 11 x 11 grid?" << endl;
            y = y - 1;
        }
        if (x > 10)
        {
            cout << "You can't go there! What do you think this is, an 11 x 11 grid?" << endl;
            x = x - 1;
        }
        if (x < 1)
        {
            cout << "You can't go there! It doesn't work like that!" << endl;
            x = x + 1;
        }
        if (y < 1)
        {
            cout << "You can't go there! It doesn't work like that!" << endl;
            y = y + 1;
        }
        if ((x == xa) && (y == ya)) //Add item prompts
        {
            char z;
            cout << "Would you like to pick up the (item1)? Press z for yes!"<<endl;
            cin >> z;
            if (z == 'z')
            {
                item1.addItem("item1");
                cout << "Added item1!" << endl;
                xa = -1;
                ya = -1;
            }
        }
        if ((x == xb) && (y == yb))
        {
            char z;
            cout << "Would you like to pick up the (item2)? Press z for yes!"<<endl;
            cin >> z;
            if (z == 'z')
            {
                item1.addItem("item2");
                cout << "Added item2!" << endl;
                xb = -1;
                yb = -1;
            }
        }
        if ((x == xc) && (y == yc))
        {
            char z;
            cout << "Would you like to pick up the (item3)? Press z for yes!"<<endl;
            cin >> z;
            if (z == 'z')
            {
                item1.addItem("item3");
                cout << "Added item3!" << endl;
                xc = -1;
                yc = -1;
            }
        }
        cout << "Current Position: (" << x << ", " << y << ")" << endl;
        cout << "_____________________________________________" << endl;
    }
    return 0;
}

int main()
{
    changePosition();
}
