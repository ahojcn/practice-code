#include "contacts.h"

int main()
{
    //Login();
    
    contact ct;
    p_contact pct = &ct;
    pct = InitContact(pct);
    
    int select = 1;
    while(select)
    {
        Menu();
        scanf("%d", &select);
        switch(select)
        {
            case 0:
                LogInfo("Exit", "Bye!");
                exit(0);
                break;
            case 1:
                AddPerson(&pct);
                break;
            case 2:
                DeletePerson(pct);
                break;
            case 3:
                SortPerson(pct);
                break;
            case 4:
                SearchPerson(pct);
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
        }
    }
    
    
    return 0;
}
