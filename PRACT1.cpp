#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *HashTable[10];

class Operation
{
public:
    Operation()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }

    int HashFunction(int value)
    {
        int key = value % 10;
        return key;
    }

    struct node *Create(int data)
    {
        struct node *head = new node();
        head->data = data;
        head->next = NULL;
        return head;
    }

    void Display()
    {
        for (int i = 0; i < 10; i++)
        {
            struct node *temp = new node();
            temp = HashTable[i];
            cout << "HashTable[" << i << "] : ";

            while (temp != NULL)
            {
                cout << "-> " << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int searchElement(int value)
    {
        bool flag = false;
        int hash_key = HashFunction(value);
        struct node *temp = new node();
        temp = HashTable[hash_key];
        cout << "\n " << value << " found at ";

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << hash_key << " location. \n";
                flag = true;
                break;
                return 0;
            }
            temp = temp->next;
        }
        if (flag == false)
        {
            cout << "Element not found! \n";
            return -1;
        }
        return 0;
    }

    void delete_element(int value)
    {
        struct node *temp = new node();
        int hash_key = HashFunction(value);
        temp = HashTable[hash_key];
        bool flag = false;

        if (temp == NULL)
            cout << "Already Empty! \n";

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << temp->data << " is deleted successfully! \n";
                free(temp);
                temp = temp->next;
                flag = true;
                break;
            }
            temp = temp->next;
        }

        if (flag == false)
            cout << "Element not found/ not deleted! \n";

        HashTable[hash_key] = temp;
    }

    void insertElement(int value)
    {
        int hash_key = HashFunction(value);
        struct node *temp = new node();
        struct node *head = new node();

        head = Create(value);

        temp = HashTable[hash_key];
        if (temp == NULL)
        {
            HashTable[hash_key] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }

    /*
            void insertElement_LP (int value)  //Linear probing 
    {
        int hash_value = HashFunction(value); 
        struct node *temp = new node(); 
        struct node* head = new node(); 
        head = Create(value); 
        temp = HashTable[hash_value]; 

        if (temp == NULL)
        {
            HashTable[hash_value] = head;
        }
        else
        {
            HashTable[(hash_value+1)%10] = head;
        }
    }
    */
};

int main()
{
    int ch;
    int data, search, del;
    Operation O;

    do
    {
        cout << "\n-------------------------------------------\n Telephone Book Database:\n Select operation number to be performed : \n 1. Insert \n 2. Display \n 3. Search \n 4. Delete \n 5. Exit \n Enter your choice:  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\n Enter phone no. to be inserted: ";
            cin >> data;
            O.insertElement(data);
            break;

        case 2:
            O.Display();
            break;

        case 3:
            cout << "\n Enter the no to be searched: ";
            cin >> search;
            if (O.searchElement(search) == -1)
            {
                cout << "No element found at key";
                continue;
            }
            break;

        case 4:
            cout << "\n Enter the phone number to be deleted: ";
            cin >> del;
            O.delete_element(del);
            cout << "Phone number deleted" << endl;
            break;
        }
    } while (ch != 5);
    return 0;
}