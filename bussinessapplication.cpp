#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
// data structures parallel arrays
string usernames[100];
string passwords[100];
int usercount = 0;
int usercounter = 0;
string sbrand[100]; // sellerbrand that he want to add
string sellerp[100];
int price[100]; // product price
int pquantity[100];
int productcount = 0; // for product this is counter
string cart[100];     // cart
int cartcount = 0;    // cart
string name[100];     // share
string share[100];    // share
int sharecount;       // share
string messagecustomer[100];
string message;
string bproduct;
int messagecount = 0;
int buycount = 0;
string buyp[100];
string brandname;
int takechoice();
int size = 0;
int size1 = 0;
string product;
int k; // key to declare seller or customer
int pprice;
int choice = 3;
string product2;
string product1; // cart
string sproduct; // shareproduct with person;  //share
string sname;    // this is person with which product is being shared  //share
// PROTOTYPES
void frame1();
void addbrand(string brandname);
void storetofilebrand(string brandname);
bool ispresenbrand(string brandname);
void seller();
void sellerbrand();
void sellerproducts();
void sp();
void loaddatafromfilesbrand(string brandname);
void signUP(string username, string password);
bool signIn(string username, string password);
void storetofile(string username, string password);
bool isvalidusername(string username);
void loaddatafromfile();
void viewUsers();
void loaddatafromfilesbrand();
void loaddatafromfilesproduct();
void storetofileproduct(string product, int quantity, int price);
void seeproducts();
string parsedata(string line, int field);
void deletep();
void delproductofbrand();
void seebrand();
bool ispresentproduct(string product);
void customer();
void seequantity();
bool flagproduct = false;
bool pcartdecision = false;          // product is available or not in array
bool cartproduct(string product1);   // cart
void addcartparray();                // store product in cart array  //cart
void loaddatafromcart();             // cart
void storefilecart(string product1); // cart
void addpcart();                     // cart
void seecart();                      // cart
bool cartdelete(string product2);    // this functio is for checking thatproduct that you want to delete is present in cart
void deletepcart();                  // cart
void seebrandseller();
void updateproductfile();
void updatecartfile();                   // cart
void shareproduct();                     // share
void loaddatafromsharefile();            // share
bool shareproductcheck(string sproduct); // share
void storefileshare();                   // share
bool psharedecision;                     // share
void shareinarray();
void chat();
void displaymessage();
void putmessageinarray();
void chat();
void buyproduct();
bool customerbuy();
void addinarraybuyproduct();
void seeselledproduct();
void seeshare();
void frame();
void customerseller();
void seeproductsforseller();
void exit();

void frame1()
{

    cout << "                  ************************************************ " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  **********clothing management system************ " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  *                                              * " << endl;
    cout << "                  ************************************************ " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void frame()
{
    cout << "                                                    " << endl;
    cout << "                                                    " << endl;
    cout << "                                                    " << endl;
    cout << "                        ___        ___" << endl;
    cout << "                      //  \\\\_____//   \\\\        " << endl;
    cout << "                    // |              | \\\\    " << endl;
    cout << "                  //   |              |   \\\\" << endl;
    cout << "                  -----|     A.K      |-----    " << endl;
    cout << "                       |              |       " << endl;
    cout << "                       |              |       " << endl;
    cout << "                       |              |       " << endl;
    cout << "                       |              |        " << endl;
    cout << "                       |______________|        " << endl;
    cout << "                                                  " << endl;
    cout << "                                                    " << endl;
}
main()
{
    loaddatafromfile();
    loaddatafromfilesbrand();
    loaddatafromfilesproduct();
    loaddatafromcart();
    loaddatafromsharefile();
    string username;
    string password;
    bool decision;

    while (choice != 0)
    {
        choice = takechoice();
        if (choice == 1)
        {
            system("CLS");
            frame();
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            decision = isvalidusername(username);
            if (decision = true)
            {
                frame();
                signUP(username, password);
                storetofile(username, password);

                cout << "CREATED SUCCESSFULLY " << endl;
            }
            else
            {
                cout << "USERNAME ALREADY EXISTS" << endl;
            }
        }
        if (choice == 2)
        {
            cout << "Enter username:";
            cin >> username;
            cout << "Enter password:";
            cin >> password;
            decision = signIn(username, password);
            if (decision == true)
            {
                system("CLS");
                frame();

                cout << "LOGIN SUCCESSfully" << endl;
                cout << "1. customer" << endl;
                cout << "2. seller" << endl;
                cout << "press any key" << endl;
                cin >> k;
                if (k == 1)
                {
                    customer();
                }
                if (k == 2)
                {
                    seller();
                }
            }
            else
            {
                cout << "login failed" << endl;
            }
        }
        if (choice == 3)
        {
            break;
        }
    }
    
}
void signUP(string username, string password)
{
    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
    getch();
}
void storetofile(string username, string password)
{
    fstream file;
    file.open("x.txt", ios::app);
    file << username << "," << password << endl;
    file.close();
}
void viewUsers()
{
    cout << "USERNAME"
         << "\t\t"
         << "password" << endl
         << endl;
    for (int index = 0; index < usercount; index++)
    {
        cout << usernames[index] << "\t\t\t" << passwords[index] << endl;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
bool signIn(string username, string password)
{
    bool flag = false;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] == username && passwords[index] == password)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool isvalidusername(string username)
{
    bool flag = false;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] != username)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int takechoice()

{
    system("CLS");
    frame1();
    int choice;
    cout << "1.SIGNUP" << endl;
    cout << "2.SIGNIN" << endl;
    cout << "3.exit" << endl;
    cout << "ENTER CHOICE:";
    cin >> choice;
    return choice;
}
void loaddatafromfile()
{
    fstream file;
    string line;
    file.open("x.txt", ios::in);
    while (getline(file, line))
    {

        usernames[usercount] = parsedata(line, 1);
        passwords[usercount] = parsedata(line, 2);
        usercount++;
    }
    file.close();
}
string parsedata(string line, int field)
{
    int commacount = 1;
    string item = "";
    int length = line.length();
    for (int i = 0; i < length; i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        else if (field == commacount)
        {
            item = item + line[i];
        }
    }
    return item;
}
void seller()

{
    system("CLS");
    frame();

    cout << "press 1 if you want to add brands" << endl;
    cout << "press 2 to add products and their quantity and prices in your collection" << endl;
    cout << "press 3 to see about products" << endl;
    cout << "press 4 to delete products from brands collection that are selled" << endl;
    cout << "press 5 to see feedback" << endl;
    cout << "press 6 to see selled product" << endl;
    cout << "press 7 to see accounts that have been login" << endl;
    cout << "press 8 to see shared product " << endl;
    cout << "press 9 if you want to go main menu " << endl;
      cout <<"press 10 if you want to exit" << endl;
    cout << "press any key you want to enter" << endl;
    int key1;
    cin >> key1;

    if (key1 == 1)
    {
        system("CLS");
        sellerbrand();
        storetofilebrand(brandname);
    }
    if (key1 == 2)
    {
        system("CLS");

        sp();
        // storetofileproduct(brand);
        //  sellerproducts();
    }
    if (key1 == 3)
    {
        system("CLS");

        seeproductsforseller();
        getch();
    }
    if (key1 == 4)
    {
        system("CLS");

        deletep(); // delete product
        // delproductofbrand();
    }
    if (key1 == 5)
    {
        system("CLS");

        displaymessage();
    }
    if (key1 == 6)
    {
        system("CLS");

        seeselledproduct();
    }
    if (key1 == 7)
    {
        system("CLS");

        viewUsers();
    }
    if (key1 == 8)
    {
        system("CLS");

        seeshare();
    }
    if (key1 == 10)
    {
        cout << "to exit press 3 " << endl;
        cin >> choice;
    }
    if(key1==9)
    {
        customerseller();
    }

    Sleep(1000);
    getch();
}

void storetofilebrand(string brandname)
{

    fstream file;
    file.open("m.txt", ios::app);
    file << brandname << endl;
    file.close();
}
void sellerbrand()
{
    cout << "how many brands you want to enter" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "enter brands name: ";
        cin >> sbrand[i];
        //  cout<<sbrand[i]<<"this brands has been added"<<endl;
        storetofilebrand(sbrand[i]);
        
       
    }
    usercounter = usercounter + size;

    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
void brands()
{
    for (int i = 0; i < usercounter; i++)
    {
    }
}
void loaddatafromfilesbrand()
{
    fstream file;
    string line = "";
    file.open("m.txt", ios::in);

    while (!file.eof())
    {
        getline(file, line);
        sbrand[usercounter] = line;
        usercounter++;
    }
    file.close();
    getch();
}
void sellerproducts()
{

    cout << "how many products you want to enter in this brand" << endl;

    cin >> size1;

    for (int j = 0; j < size1; j++)
    {
        cout << "enter products name:  ";
        cin >> sellerp[j];
        cout << "enter product quantity: ";
        cin >> pquantity[j];
        cout << "enter product price: ";
        cin >> price[j];
        storetofileproduct(sellerp[j], pquantity[j], price[j]);
    }
    productcount = productcount + size1;
}
void storetofileproduct(string product, int quantity, int price)
{
    fstream file;
    file.open("p.txt", ios::app);
    // cout<<sellerp[i]<<endl;

    file << "\n"
         << product << "," << quantity << "," << price;
    file.close();
}
void loaddatafromfilesproduct()
{
    fstream file;
    string line;
    file.open("p.txt", ios::in);

    while (!file.eof())
    {
        // if (getline(file, line))
        // {
        getline(file, line);
        // cout<<parsedata(line, 1)<<endl;
        // cout<<parsedata(line, 2)<<endl;
        // cout<<parsedata(line, 3)<<endl;

        getch();

        // sbrand[usercounter] = parsedata(line, 1);
        sellerp[productcount] = parsedata(line, 1);
        pquantity[productcount] = stoi(parsedata(line, 2));
        price[productcount] = stoi(parsedata(line, 3));
        productcount++;
        //}
    }
    file.close();
}

void sp() // sellerproduct
{

    cout << "enter brandname in which you want to add products" << endl;
    cin >> brandname;
    bool decision = false;
    decision = ispresenbrand(brandname);
    if (decision == true)
    {
        cout << "present" << endl;
        sellerproducts();
    }
    else
    {
        cout << "not present" << endl;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
bool ispresenbrand(string brandname)
{
    bool flag = false;
    for (int index = 0; index < usercounter; index++)
    {
        if (sbrand[index] == brandname)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void seeproducts()
{
    cout << "product" << endl;
    for (int index = 0; index < productcount; index++)
    {
        cout << sellerp[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
void seeproductsforseller()
{
    cout << "product" << endl;
    for (int index = 0; index < productcount; index++)
    {
        cout << sellerp[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
void seebrand()
{
    cout << "brands" << endl;

    for (int index = 0; index < usercounter; index++)
    {
        cout << sbrand[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
void seebrandseller()
{
    cout << "brands" << endl;

    for (int index = 0; index < usercounter; index++)
    {
        cout << sbrand[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
void seequantity()
{
    cout << "product"
         << "\t\t\t"
         << "quantity"
         << "\t\t\t"
         << "price" << endl;
    for (int index = 0; index < productcount; index++)
    {
        cout << sellerp[index] << "\t\t\t" << pquantity[index] << "\t\t\t" << price[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}

void deletep() // rough
{
    string product4;
    int idx;
    // system("CLS");
    frame();
    bool decision = false;
    cin.ignore(365, '\n');
    // decision = ispresentproduct(product);
    cout << "enter  product you want to delete" << endl;
    cin >> product4;

    for (int index = 0; index < productcount; index++)
    {
        if (product4 == sellerp[index])
        {
            decision = true;
            idx = index;
            break;
        }
    }
    if (decision == true)
    {
        for (int j = idx; j < productcount; j++)
        {
            sellerp[j] = sellerp[j + 1];
            pquantity[j] = pquantity[j + 1];
            price[j] = price[j + 1];
        }
        productcount--;
        updateproductfile();
        cout << product4 << "is deleated" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
void updateproductfile()
{
    fstream file;
    file.open("p.txt", ios::out);
    for (int i = 0; i < productcount; i++)
    {
        file << sellerp[i] << ",";
        file << pquantity[i] << ",";
        file << price[i] << endl;
    }
    file.close();
}

// bool ispresentproduct(string product) // rough
// {

//     int idx;
//     for (int index = 0; index < productcount; index++)
//     {
//         if (sellerp[index] == product)
//         {
//             flagproduct = true;

//             break;
//         }
//     }

//     return flagproduct;
// }
// void delproductofbrand() // rough
// {

//     int idx;
//     fstream file;
//     file.open("p.txt", ios::out);

//     for (int index = 0; index < productcount; index++)
//     {
//         if (sellerp[index] == product)
//         {
//             index = idx;
//             sellerp[idx] = " ";
//             break;
//         }
//         else
//         {
//         }

//     }
//     file.close();
//       int key1;
//     cout << "if you want to go meanu option please enter 1 " << endl;
//     cin >> key1;
//     if (key1 == 1)
//     {
//         seller();
//     }
// }
void customer()
{
    system("CLS");
    frame();
    int key1;
    cout << " press 1 to see product    " << endl;
    cout << " press 2 to see the brand you want is available                         " << endl;
    cout << " press 3 to see product quantity                             " << endl;
    cout << " press 4 to add products into cart for buy     " << endl;
    cout << " press 5 to see product that he enter in cart      " << endl;
    cout << " press 6 to delete the product from cart         " << endl;
    cout << " press 7 to share the product                            " << endl;
    cout << " press 8 to buy product  " << endl;
    cout << " press 9 to give feedback " << endl;
    cout << " press 10 to go to  main menu " << endl;
    cout << " press 11 if you want to exit " << endl;
    cout << " press any key you want to enter" << endl;

    cin >> key1;
    if (key1 == 10)
    {
        system("CLS");
    }
    if (key1 == 1)
    {
        system("CLS");
        seeproducts();
    }
    if (key1 == 2)
    {
        system("CLS");
        seebrand();
    }
    if (key1 == 3)
    {
        system("CLS");
        seequantity();
    }
    if (key1 == 7)
    {
        system("CLS");
        shareproduct();
    }
    if (key1 == 9)

    {
        system("CLS");
        chat();
    }

    if (key1 == 4)
    {
        system("CLS");
        addpcart();
    }
    if (key1 == 5)
    {
        system("CLS");
        seecart();
    }
    if (key1 == 6)
    {
        system("CLS");
        deletepcart();
    }
    if (key1 == 8)
    {
        system("CLS");
        buyproduct();
    }
    if (key1 == 10)
    {customerseller();
    } 
    if (key1 == 11)
    {
        system("CLS");
        cout << "to exit press 3 " << endl;
        cin >> choice;
    }
}
void customerseller()
{  system("CLS");
   frame();
    int k;
    cout << "1. customer" << endl;
    cout << "2. seller" << endl;
    cout << "press any key" << endl;
    cin >> k;
    if (k == 1)
    {
        customer();
    }
    if (k == 2)
    {
        seller();
    }
}

void addpcart()
{
    cout << "enter product that you want to add in cart" << endl;
    cin >> product1;
    pcartdecision = cartproduct(product1);
    if (pcartdecision == true)
    {

        addcartparray();
        storefilecart(product1);
        cartcount++;
    }
    else
    {
        cout << "not present" << endl;
        cartcount = cartcount;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
bool cartproduct(string product1)
{
    bool flag = false;
    for (int index = 0; index < productcount; index++)
    {
        if (sellerp[index] == product1)
        { // index=idx;
            flag = true;
            break;
        }
    }
    return flag;
}
void addcartparray()
{
    cart[cartcount] = product1;
    cartcount++;
}
void storefilecart(string product1)
{
    fstream file;
    file.open("cart.txt", ios::app);
    file << product1 << endl;
    file.close();
}
void loaddatafromcart()
{
    fstream file;
    string line;
    file.open("cart.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cart[cartcount] = line;
        cartcount++;
    }
    file.close();
    // getch();
}
void seecart()
{
    cout << "product" << endl;

    for (int index = 0; index < cartcount; index++)
    {
        cout << cart[index] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
void deletepcart()
{
    int idx;
    pcartdecision = false;
    cin.ignore(365, '\n');
    cout << "enter product ypu want to delete from cart" << endl;
    cin >> product2;
    for (int index = 0; index < cartcount; index++)
    {
        if (product2 == cart[index])
        {
            pcartdecision = true;
            idx = index;
            break;
        }
    }
    if (pcartdecision == true)
    {
        for (int i = idx; i < cartcount; i++)
        {
            cart[i] = cart[i + 1];
        }
        cartcount--;
        updatecartfile();
        cout << product2 << "is deleted" << endl;
    }
    else
    {
        cout << "not present" << endl;
        cartcount = cartcount;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
void updatecartfile()
{

    fstream file;
    file.open("cart.txt", ios::out);
    for (int i = 0; i < cartcount; i++)
    {
        file << cart[i] << endl;
    }
    file.close();
    getch();
}
void shareproduct()
{  system("CLS");
   frame();
    cout << "enter product you want to share: " << endl;
    cin >> sproduct;
    psharedecision = shareproductcheck(sproduct);
    if (pcartdecision == true)
    {
        cout << "enter whome with you want to share product: " << endl;
        cin >> sname;
        shareinarray();
        storefileshare();
        sharecount++;
    }
    else
    {
        cout << "not present" << endl;
        sharecount = sharecount;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
bool shareproductcheck(string sproduct)
{
    bool flag = false;
    for (int index = 0; index < productcount; index++)
    {
        if (sellerp[index] == sproduct)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void shareinarray()
{

    share[sharecount] = sproduct;
    name[sharecount] = sname;
    sharecount++;
}
void storefileshare()
{
    fstream file;
    file.open("share.txt", ios::app);
    file << sname << ",";
    file << sproduct << endl;
    file.close();
}
void loaddatafromsharefile()
{

    fstream file;
    string line;
    file.open("share.txt", ios::in);
    while (!file.eof())
    {
        if (getline(file, line))
        {

            share[sharecount] = parsedata(line, 1);
            name[sharecount] = parsedata(line, 2);
            sharecount++;
        }
    }
    file.close();
    // getch();
}
void seeshare()
{  system("CLS");
   frame();
    for (int i = 0; i < sharecount; i++)
    {
        cout << "shared product is: " << name[i] << endl;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}

void chat()
{
    cout << "enter message" << endl;
    cin >> message;
    messagecount++;
    putmessageinarray();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
void putmessageinarray()
{

    messagecustomer[messagecount] = message;
    messagecount++;
}
void displaymessage()
{
    for (int i = 0; i < messagecount; i++)
    {
        cout << messagecustomer[i] << endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}
void buyproduct()
{  
    cout << "enter product you want to buy" << endl;
    cin >> bproduct;
    bool ispresentbuy = customerbuy();
    if (ispresentbuy == true)
    {
        addinarraybuyproduct();
        cout << "you have buy this product" << endl;
        buycount++;
    }
    else
    {
        cout << "not present" << endl;
        buycount = buycount;
    }
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        customer();
    }
}
bool customerbuy()
{
    bool flag = false;
    for (int index = 0; index < cartcount; index++)
    {
        if (cart[index] == bproduct)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void addinarraybuyproduct()
{
    buyp[buycount] = bproduct;
    buycount++;
}
void seeselledproduct()
{   system("CLS");
   frame();
    for (int i = 0; i < buycount; i++)
    {
        cout << "selled product is: " << bproduct<<endl;
    }
    getch();
    int key1;
    cout << "if you want to go meanu option please enter 1 " << endl;
    cin >> key1;
    if (key1 == 1)
    {
        seller();
    }
}