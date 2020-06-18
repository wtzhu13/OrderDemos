#include "ui.h"
#include "user.h"

int main()
{
    User user;
    Ui ui;
    ui.showMainMenu();
    int menuChoice;
    cin >> menuChoice;
    switch (menuChoice)
    {
    case 1:
        user.addUser();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    default:
        break;
    }
    return 0;
}