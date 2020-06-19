#include "ui.h"
#include "user.h"

int main()
{
    User user;
    Ui ui;
    while (1)
    {
        ui.showMainMenu();
        int menuChoice;
        cin >> menuChoice;
        switch (menuChoice)
        {
        case 1:
            user.addUser();
            break;
        case 2:
            user.delContase();
            break;
        case 3:
            user.modifyInfo();
            break;
        case 4:
            user.findContase();
            break;
        case 5:
            user.showAllContaces();
            break;
        case 6:
            user.fromPhoneToCard();
            break;
        case 7:
            user.fromCardToPhone();
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}