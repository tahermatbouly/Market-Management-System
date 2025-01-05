#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // For system()
#include <conio.h>

using namespace std;

string maskedInput() // BY SEREACH
{
	string input;
	char ch;

	while ((ch = _getch()) != '\r') { // Read characters until Enter is pressed
		if (ch == '\b') { // Handle backspace
			if (!input.empty()) {
				cout << "\b \b"; // Erase previous character
				input.pop_back();
			}
		}
		else {
			cout << '*'; // Display an asterisk for each character
			input += ch;
		}
	}

	cout << endl;
	return input;
}

class admin {
public:
	int admin_id;
	string name;
	string password;
	admin* pnext;
};

class Cadmin {
public:
	admin* phead;
	admin* ptail;

	Cadmin()
	{
		phead = NULL;
		ptail = NULL;
	}

	~Cadmin() {
		admin* ptrav = phead;
		while (phead != NULL) {
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}

	void Attach(admin* pnn) {
		if (phead == NULL) {
			phead = ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

};

class customer {
public:
	int cid;
	string cname;
	string cpassword;
	customer* pnext;
};

class Ccustomer {
public:
	customer* phead;
	customer* ptail;

	Ccustomer()
	{
		phead = NULL;
		ptail = NULL;
	}

	~Ccustomer() {
		customer* ptrav = phead;
		while (phead != NULL) {
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}

	void Attach(customer* pnn) {
		if (phead == NULL) {
			phead = ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

};

class product
{
public:
	int pro_id;
	string pro_name;
	int quantity;
	int price;
	int exp_m;
	int exp_y;
	product* pnext;
};

class Cproduct
{
public:
	product* phead;
	product* ptail;

	Cproduct()
	{
		phead = NULL;
		ptail = NULL;
	}

	~Cproduct() {
		product* ptrav = phead;
		while (phead != NULL) {
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}

	void Attach(product* pnn) {
		if (phead == NULL) {
			phead = ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void insert()
	{
		int ct = 0;
		ifstream myfile_po;
		ofstream myfile_p;
		myfile_p.open("product.txt", ios::app);

		myfile_po.open("product.txt");
		string str;
		string temp = " ";
		string temp2 = " ";
		product* pnn = NULL;
		while (getline(myfile_po, str))
		{

			if (ct == 0 || ct % 7 == 0)
			{
				pnn = new product;
			}


			int f = 0;
			for (int i = 0; i < str.length(); i++)
			{

				if (ct == 0)
				{
					if (str[i] == ' ')
					{
						f = 1;
						i++;
						temp = ' ';
						temp2 = ' ';
					}

					if (f == 1)
					{
						temp = str[i];
						pnn->pro_id = stoi(temp);
					}
				}
				if (ct == 1)
				{
					if (str[i] == ' ')
					{
						temp = ' ';
						f = 1;
						i++;
					}

					if (f == 1)
					{
						temp += str[i];
						if (i + 1 == str.length())
							pnn->pro_name = temp;
					}
				}
				if (ct == 2)
				{
					if (str[i] == ' ')
					{
						temp = ' ';
						temp2 = ' ';

						f = 1;
						i++;
					}

					if (f == 1)
					{
						temp2 = str[i];
						temp.append(temp2);
						if (i + 1 == str.length())
							pnn->quantity = stoi(temp);
					}
				}
				if (ct == 3)
				{
					if (str[i] == ' ')
					{
						temp = ' ';
						temp2 = ' ';

						f = 1;
						i++;
					}

					if (f == 1)
					{

						temp2 = str[i];
						temp.append(temp2);
						if (i + 1 == str.length())
							pnn->price = stoi(temp);
					}
				}
				if (ct == 4)
				{
					if (str[i] == ' ')
					{
						temp = ' ';
						temp2 = ' ';

						f = 1;
						i++;
					}

					if (f == 1)
					{

						temp2 = str[i];
						temp.append(temp2);
						if (i + 1 == str.length())
							pnn->exp_m = stoi(temp);
					}
				}
				if (ct == 5)
				{
					temp = ' ';
					temp2 = ' ';

					if (str[i] == ' ')
					{
						f = 1;
						i++;
					}

					if (f == 1)
					{

						temp2 = str[i];
						temp.append(temp2);
						if (i + 1 == str.length())
							pnn->exp_y = stoi(temp);
					}
				}




			}
			ct++;
			if (ct == 6)
			{
				Attach(pnn);
			}
			if (ct == 7)
			{
				ct = 0;
			}
		}
	}

};

class order
{
public:
	int order_id;
	int pro_id;
	int date;
	int cart;
	int cust_id;
	order* pnext;
	order()
	{
		cust_id = 0;
		cart = 0;
		date = 0;
		pro_id = 0;
		order_id = 0;
		pnext = NULL;
	}

};

class Corder
{
public:

	order* phead;
	order* ptail;

	Corder()
	{
		phead = NULL;
		ptail = NULL;
	}

	~Corder() {
		order* ptrav = phead;
		while (phead != NULL) {
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}

	void Attach(order* pnn) {
		if (phead == NULL) {
			phead = ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}

	void display_all() {
		order* ptrav = phead;
		if (ptrav == NULL)
		{
			cout << " \n NO ORDER TO VIEW";
		}
		while (ptrav != NULL)
		{
			cout << endl << "order id :" << ptrav->order_id;
			cout << endl << "product id :" << ptrav->pro_id;
			cout << endl << "customer id :" << ptrav->cust_id;
			cout << endl << "date :" << ptrav->date;
			cout << endl << "cart :" << ptrav->cart;
			if (ptrav->pnext == NULL)
			{
				break;
			}

			ptrav = ptrav->pnext;
		}
	}

	void insert3()
	{
		order* pnn = NULL;
		ifstream myfile_or;
		myfile_or.open("order.txt");

		string str;
		int ct = 0;

		while (getline(myfile_or, str))
		{

			if (ct == 0) {
				pnn = new order;
			}


			string temp;
			int f = 0;

			for (int i = 0; i < str.length(); i++)
			{
				if (i == 3)
				{
					f = 1;
					i++;
				}

				if (f == 1)
				{
					temp += str[i];
					if (i + 1 == str.length())
					{
						if (ct == 0)
						{
							pnn->order_id = stoi(temp);
						}
						else if (ct == 1)
						{
							pnn->pro_id = stoi(temp);
						}
						else if (ct == 2)
						{
							pnn->cust_id = stoi(temp);
						}
						else if (ct == 3)
						{
							pnn->date = stoi(temp);
						}
						else if (ct == 4)
						{
							pnn->cart = stoi(temp);
							Attach(pnn);
						}
					}
				}
			}

			ct++;
			if (ct == 5)
			{
				ct = 0;
			}
		}

		myfile_or.close();
	}
};

void main()
{
	Cadmin A;
	Cproduct P;
	Corder O;
	Ccustomer C;
	int admintry = 0;
	int AC;  //Admin Customer
	string CustName;
	int ct = 0;
	int id = 0;
	int aid = 0;
	int pro_id = 0;
	int ord_id = 0;
	string CustPass;

	O.insert3();
	P.insert();




	for (;;)
	{
		cout << "\n1)Adimn" << endl << endl << "\n2)Customer" << endl << endl << "\n3)exit" << endl;
		cin >> AC;

		// this part takes u to the admin part and u have only 3 times to login correctly or u will be blocked 
		if (admintry < 3)
		{
			// u are an admin
			if (AC == 1)
			{
				system("cls");
				int fadmin = 0;
				cout << endl << "1)new admin account" << endl << "2)old admin " << endl;
				cin >> fadmin;
				//new admin
				if (fadmin == 1)
				{

					int f = 0;

					ofstream myfile_a;
					ifstream myfile_ad;
					string str_a;
					myfile_a.open("admin.txt", ios::app);
					myfile_ad.open("admin.txt");
					// check and generate new id 
					while (f != 1)
					{

						ifstream myfile_ad("admin.txt");
						string str;
						string tempp;
						int temp;
						while (getline(myfile_ad, str))
						{
							for (int i = 0; i < str.length(); i++)
							{
								if (i == 3)
								{
									tempp = str[i];
									break;
								}
							}
							temp = stoi(tempp);// function change string to integer form
							if (temp == aid)
							{
								aid++;
								f = 0;

							}


						}
						f = 1;

					}









					system("cls");
					admin* pnn = new admin;



					cout << "\nur id is :" << aid;// add id to linked list
					pnn->admin_id = aid;
					myfile_a << "ID:" << pnn->admin_id;


					cout << "\nenter admin's name :";
					cin >> pnn->name;
					myfile_a << "  " << "NAME:" << pnn->name;

					cout << "\nenter admin's password :";
					cin >> pnn->password;
					myfile_a << "  " << "PASSWORD:" << pnn->password;
					myfile_a << endl;
					myfile_a.close();

					A.Attach(pnn);
					cout << "\n!! congratulation now u are admin here MR  " << pnn->name << "!!";
					admin* ptrav = A.phead;


					int x;
					cin >> x;


				}

				//old admin
				if (fadmin == 2)
				{
					int n_id;
					string n_pass;
					cout << "\nenter id :";
					cin >> n_id;
					cout << "\nenter ur password :";
					n_pass = maskedInput();// for cin the hidden password لو عايزه تشليها يا دكتوره مفيش مشكله
					admin* ptrav = A.phead;
					int pcheck = 0;
					// to check is the user is the admin or not





					int f = 0;

					ofstream myfile_a;
					ifstream myfile_ad;
					string str_a;
					myfile_a.open("admin.txt", ios::app);
					myfile_ad.open("admin.txt");
					// check the admin in the file
					while (f != 1)
					{

						ifstream myfile_ad("admin.txt");
						string str;
						string tempp1;// the string that will be an intger
						string tempp2;
						int temp;
						while (getline(myfile_ad, str))
						{
							for (int i = 0; i < str.length(); i++)
							{
								if (i == 3)
								{
									tempp1 = str[i];

								}

							}
							temp = stoi(tempp1);// function change string to integer form



							// if the id of admin is correct he will enter
							if (temp == n_id)
							{
								int ff = 0;
								int i = str.length() - 1;

								for (int j = n_pass.length() - 1; j >= 0; j--)
								{
									if (n_pass[j] != str[i])
									{
										break;
										ff = 0;
									}
									i--;
									if (j - 1 < 0)
									{
										ff = 1;
									}
								}
								//if the password of admin is correct he will enter
								if (ff == 1)
								{
									myfile_ad.close();
									for (;;)
									{
										pcheck = 1;
										system("cls");
										cout << "welcome back sir";
										cout << "\n1)manage product. " << endl << "\n2)mointor order" << endl << "\n3)check income" << endl << "\n4)view all the product" << endl << "\n5)exit";
										int choise;
										cout << "\nenter ur choise : ";
										cin >> choise;





										//manage product
										if (choise == 1)
										{
											//stock alert
											product* ptrav = P.phead;
											while (ptrav != NULL)
											{
												if (ptrav->quantity <= 0)
												{
													system("cls");
													cout << "!!!!!!!!!!WARNING!!!!!!!!!!" << endl;
													cout << "sorry sir but the item " << " " << ptrav->pro_name << " and its id is :" << ptrav->pro_id;
													cout << endl << " is out of stock!!!" << "\n pls add it from add product immediatly";
													int u;
													cin >> u;

												}
												ptrav = ptrav->pnext;
											}




											system("cls");
											cout << "\n1)add product" << endl << "\n2)edit product" << endl << "\n3)delete product" << endl << "\n4)exit" << endl;
											int ch;
											cin >> ch;


											//add product
											if (ch == 1)
											{


												system("cls");
												//new product


												int f = 0;

												ofstream myfile_p;
												ifstream myfile_po;
												string str_p;
												myfile_p.open("product.txt", ios::app);
												myfile_po.open("product.txt");
												// check and generate new id 
												while (f != 1)
												{


													string tempp;
													int temp;
													int ct = 0;
													if (myfile_po.is_open())
													{
														while (getline(myfile_po, str_p))
														{
															if (ct == 0 || ct % 7 == 0)
															{

																for (int i = 0; i < str_p.length(); i++)
																{
																	if (i == 4)
																	{
																		tempp = str_p[i];
																		break;
																	}
																}
																temp = stoi(tempp);// function change string to integer form
																if (temp == pro_id)
																{
																	pro_id++;
																	f = 0;

																}

															}
															ct++;

														}
														f = 1;
													}
													else {
														cout << " not";
													}

												}

												system("cls");
												product* pnn = new product;
												if (myfile_p.is_open())
												{
													cout << "\nproduct id is :" << pro_id;// add id to linked list
													pnn->pro_id = pro_id;
													myfile_p << "ID:" << " " << pnn->pro_id << endl;


													cout << "\nenter product's name :";
													cin >> pnn->pro_name;
													myfile_p << "NAME:" << " " << pnn->pro_name << endl;

													cout << "\nenter product quantity:";
													cin >> pnn->quantity;
													myfile_p << "quantity:" << " " << pnn->quantity << endl;

													cout << "\nenter product price:";
													cin >> pnn->price;
													myfile_p << "price:" << " " << pnn->price << endl;

													cout << "\nenter product expire month:";
													cin >> pnn->exp_m;
													myfile_p << "expire_month:" << " " << pnn->exp_m << endl;

													cout << "\nenter product expire year:";
													cin >> pnn->exp_y;
													myfile_p << "expire_year:" << " " << pnn->exp_y << endl;

													myfile_p << endl;
													myfile_p.close();




													P.Attach(pnn);
													product* ptrav = P.phead;


													int x;
													cin >> x;
												}



											}



											//edit product
											if (ch == 2)
											{

												system("cls");
												int index;
												cout << "\n enter id of product u want to edit :";
												cin >> index;

												product* ptravv = P.phead;
												while (ptravv != NULL)
												{

													if (ptravv->pro_id == index)
													{
														cout << "\nu are editing item " << ptravv->pro_name;
														cout << "\n1)edit quantity" << endl << "\n2)price" << endl;
														int chooose;
														cout << "\nenter ur choise :";
														cin >> chooose;
														if (chooose == 1)
														{
															system("cls");
															int newq;
															cout << " enter the new quantity";
															cin >> newq;
															ptravv->quantity = newq;
															cout << "\n misson done!!!";
															int v;
															cin >> v;
														}
														if (chooose == 2)
														{
															system("cls");
															int newp;
															cout << " enter the new price";
															cin >> newp;
															ptravv->price = newp;
															cout << "\n misson done!!!";
															int v;
															cin >> v;
														}
														system("cls");
														cout << "here is the item" << ptravv->pro_name << "after modification:";
														cout << "\n the product id" << ptravv->pro_id;
														cout << "\n the product name" << ptravv->pro_name;
														cout << "\n the product price" << ptravv->price;
														cout << "\n the product quantity" << ptravv->quantity;
														cout << "\n the product expire M/y" << ptravv->exp_m << "/" << ptravv->exp_y;
														int d;
														cin >> d;
														break;
													}

													ptravv = ptravv->pnext;
												}
												if (ptravv->pro_id != index)
												{


													cout << "\n product not found";
													int f;
													cin >> f;

												}

												ptravv = P.phead;
												ofstream myfile_po("product.txt");
												if (myfile_po.is_open()) {
													while (ptravv != NULL) {

														myfile_po << "ID:" << " " << ptravv->pro_id << endl;



														myfile_po << "NAME:" << " " << ptravv->pro_name << endl;


														myfile_po << "quantity:" << " " << ptravv->quantity << endl;


														myfile_po << "price:" << " " << ptravv->price << endl;


														myfile_po << "expire_month:" << " " << ptravv->exp_m << endl;


														myfile_po << "expire_year:" << " " << ptravv->exp_y << endl;
														ptravv = ptravv->pnext;
														myfile_po << endl;
													}
													myfile_po.close();
												}



											}



											//delete product
											if (ch == 3)
											{

												system("cls");
												int index;
												cout << "\n enter id of product u want to delete :";
												cin >> index;

												product* ptrav = P.phead;
												product* pback = NULL;

												while (ptrav != NULL)
												{
													if (ptrav->pro_id == index)
													{
														if (pback == NULL) {
															P.phead = ptrav->pnext;
														}
														else {
															pback->pnext = ptrav->pnext;
														}

														delete ptrav;
														cout << "Item with Id " << index << " deleted from list." << endl;
														int c;
														cin >> c;
														break;
													}
													pback = ptrav;
													ptrav = ptrav->pnext;
												}


												ptrav = P.phead;
												ofstream myfile_po("product.txt");
												if (myfile_po.is_open()) {
													while (ptrav != NULL) {

														myfile_po << "ID:" << " " << ptrav->pro_id << endl;


														myfile_po << "NAME:" << " " << ptrav->pro_name << endl;

														myfile_po << "quantity:" << " " << ptrav->quantity << endl;

														myfile_po << "price:" << " " << ptrav->price << endl;

														myfile_po << "expire_month:" << " " << ptrav->exp_m << endl;

														myfile_po << "expire_year:" << " " << ptrav->exp_y << endl;
														ptrav = ptrav->pnext;
														myfile_po << endl;
													}
													myfile_po.close();
												}
												//product* ptravv = P.phead->pnext;
												//product* pback = P.phead;
												//int f = 0;
												//while (ptravv != NULL)
												//{
												//	// for first
												//	if (pback->pro_id == index)
												//	{
												//		f = 1;
												//		system("cls");
												//		cout << "\nu are deleting item " << ptravv->pro_name;
												//		pback->pnext = NULL;
												//		P.phead = ptravv->pnext;
												//		delete pback;
												//		cout << "\n misson done!!!";
												//		int v;
												//		cin >> v;
												//		break;
												//
												//	}
												//	// for in between and last cell
												//	else
												//	{
												//		if (ptravv->pro_id == index)
												//		{
												//			f = 1;
												//			system("cls");
												//			cout << "\nu are deleting item " << ptravv->pro_name;
												//			//for last cell
												//			if (ptravv->pnext == NULL)
												//			{
												//
												//				pback->pnext = NULL;
												//				P.ptail = pback;
												//				delete ptravv;
												//				cout << "\n misson done!!!";
												//
												//			}
												//			// for in between cell
												//			else
												//			{
												//				pback->pnext = ptravv->pnext;
												//				ptravv->pnext = NULL;
												//				delete ptravv;
												//				cout << "\n misson done!!!";
												//
												//			}
												//			int v;
												//			cin >> v;
												//			break;
												//
												//		}
												//
												//		else
												//		{
												//			cout << "\n product not found!!";
												//			int y;
												//			cin >> y;
												//
												//		}
												//
												//	}
												//
												//	if (f == 1) {
												//		break;
												//	}
												//	ptravv = ptravv->pnext;
												//	pback = pback->pnext;
												//}

											}

											//exit
											if (ch == 4)
											{
												break;
											}


										}
										//mointor the orders
										if (choise == 2)
										{
											system("cls");

											order* ptravv = O.phead;
											if (ptravv == NULL)
											{
												system("cls");
												cout << " there is no order to view Rbna yrz2 ya rais!!!";
											}
											else {
												cout << " \n here is the the order we have:" << endl;

												while (ptravv != NULL)
												{
													cout << "\n order id " << ptravv->order_id;
													cout << "\n the product which the customer take :" << ptravv->pro_id;
													cout << "\n customer id :" << ptravv->cust_id;
													cout << "\n the date of the order :" << ptravv->date;
													cout << "\n the cart of this order:" << ptravv->cart << endl << endl;

													ptravv = ptravv->pnext;

												}

											}
											int g;
											cin >> g;
										}
										//check income
										if (choise == 3)
										{
											system("cls");
											order* ptravv = O.phead;
											int tot = 0;
											while (ptravv != NULL)
											{

												while (ptravv != NULL)
												{


													if (ptravv != NULL) {
														cout << "\n order id is :" << ptravv->order_id << " its cart:" << ptravv->cart;

													}
													tot += ptravv->cart;
													ptravv = ptravv->pnext;
												}
											}
											cout << endl << "\nthe total income is :" << tot;
											int f;
											cin >> f;
										}

										// view product list
										if (choise == 4)
										{

											product* ptrav = P.phead;
											int i = 1;
											if (ptrav == NULL)
											{
												system("cls");
												cout << "\nsorry boss there is no items to view ";
											}
											while (ptrav != NULL)
											{
												if (i == 1)
													system("cls");
												cout << endl << i << ")" << ptrav->pro_name;
												ptrav = ptrav->pnext;
												i++;
											}
											int f;
											cin >> f;

										}

										// exit
										if (choise == 5)
										{
											break;
										}





									}
								}

							}


						}
						f = 1;

					}


					// to check the count of tries in admin part
					if (pcheck == 0)
					{
						system("cls");
						admintry++;
						cout << "u are not an admin , u have " << 3 - admintry << "tries";
						int x;
						cin >> x;
					}

				}


			}
		}
		else
		{
			cout << "\n sorry sir u have been blocked !!";
			int x;
			cin >> x;
		}



		if (AC == 2)
		{

			system("cls");
			cout << endl << "1)New Customer" << endl << endl << "2)have an Account " << endl;
			int cust;
			cin >> cust;
			// create new account for the customer
			if (cust == 1) {
				int f = 0;

				system("cls");
				ofstream myfile_c;
				ifstream myfile_co;
				myfile_c.open("customer.txt", ios::app);
				myfile_co.open("customer.txt");
				// check and generate new id 
				while (f != 1)
				{

					string str_c;
					string tempp;
					int temp;
					int ct = 0;

					if (myfile_co.is_open())
					{
						int lock2 = 0;
						int lock = 0;
						while (getline(myfile_co, str_c))
						{
							if (ct == 0 || ct % 4 == 0)
							{

								for (int i = 0; i < str_c.length(); i++)
								{
									if (i == 4)
									{
										tempp = str_c[i];
										break;
									}
								}
								temp = stoi(tempp);// function change string to integer form
								if (temp == id)
								{
									id++;
									f = 0;

								}

							}
							ct++;

						}

						f = 1;
					}
					else {
						cout << " not";
					}

				}

				customer* pnn = new customer;
				myfile_c << endl;
				cout << "\n your id is:" << id;
				pnn->cid = id;
				myfile_c << "ID:" << " " << pnn->cid << endl;

				cout << "\n enter your name:";
				cin >> pnn->cname;
				myfile_c << "NAME:" << " " << pnn->cname << endl;

				cout << "\n enter customer password: ";
				pnn->cpassword = maskedInput();
				myfile_c << "password:" << " " << pnn->cpassword << endl;

				myfile_c.close();


				C.Attach(pnn);

				cout << "\n !! congratulations you have an account as a customer MR " << " " << pnn->cname << " !!";

				customer* ptrav = C.phead;

				int x;
				cin >> x;
			}
			//  have already an account
			if (cust == 2)
			{
				int n_id;
				string n_pass;
				cout << "\nenter id :";
				cin >> n_id;
				cout << "\nenter ur password :";
				n_pass = maskedInput();
				customer* ptrav = C.phead;
				int pcheck = 0;



				int f = 0;

				ofstream myfile_c;
				ifstream myfile_co;
				string str_c;

				myfile_co.open("customer.txt");
				int ct = 0;

				string str;
				string tempp1 = " ";// the string that will be an 
				string tempp2;
				int temp = 1;
				int flag_exit = 0;
				ct = 0;
				int nct = 0;
				int flag = 0;
				// check the  in the file
				while (f != 1)
				{

					if (myfile_co.is_open())
					{
						string tempp;
						int ct = 0;
						while (getline(myfile_co, str))
						{
							// to get id
							if (ct % 4 == 0)
							{
								for (int i = 0; i < str.length(); i++)
								{

									if (i == 4)
									{
										tempp = str[i];
										temp = stoi(tempp);
										if (n_id == temp)
										{
											cout << temp;
											nct = ct + 2;
											flag = 1;
										}

									}

								}
							}
							// to check the password of the id 
							if (flag == 1) {
								if (ct == nct)
								{
									int y = (n_pass.length() - 1);
									cout << "\nlength of entered password:" << y;
									cout << "\nn_pass:" << n_pass;
									for (int i = (str.length()) - 1; i >= 0; i--)
									{
										// to get the end string
										if (str[i] != ' ')
										{
											if (n_pass[y] != str[i])
											{
												cout << "\nfalse";
												cout << "\nstr[i]:" << str[i] << endl << "\n n_pass:" << n_pass[y];
												break;
											}
											else
											{


												if (str[i - 1] == ' ')
												{
													for (;;)
													{
														pcheck = 1;
														system("cls");
														cout << "\nwelcome back sir" << endl;
														cout << "\n1)make order" << endl << "\n2)return order " << endl << "\n3)view the receipt" << endl << "\n4)exit";
														int chose;
														cin >> chose;
														// make order
														if (chose == 1)
														{
															system("cls");

															product* ptrav = P.phead;
															int i = 1;
															order* pnn2;
															// to check if there is product in the stock or not 
															if (ptrav == NULL)
															{
																system("cls");
																cout << "\nsorry sir there is no items to view ask the admin to add products!!! ";
																int g;
																cin >> g;
																break;
															}

															//if the linked of product contatin item it will present
															while (ptrav != NULL)
															{
																if (i == 1)
																	system("cls");
																cout << "\n here is list of our product :";
																if (ptrav->quantity > 0)
																{
																	cout << endl << i << ")" << ptrav->pro_name << " " << "id :" << ptrav->pro_id << " " << "price:" << ptrav->price << " " << "available quatity:" << ptrav->quantity << endl;
																	ptrav = ptrav->pnext;
																	i++;
																}
																else
																{
																	ptrav = ptrav->pnext;
																}


															}
															cout << " \nenter the details of the ur order: ";
															pnn2 = new order;
															int f = 0;


															ofstream myfile_o;
															ifstream myfile_or;
															myfile_o.open("order.txt", ios::app);
															myfile_or.open("order.txt");
															// check and generate new id
															int fo = 1;
															while (f != 1)
															{

																string str_c;
																string tempp;
																int temp = 1;
																int ct = 0;
																if (myfile_or.is_open())
																{
																	while (getline(myfile_or, str_c))
																	{
																		if (ct == 0 || ct % 5 == 0)
																		{

																			for (int i = 0; i < str_c.length(); i++)
																			{
																				if (i == 4)
																				{
																					tempp = str_c[i];
																					temp = stoi(tempp);// function change string to integer form
																					if (temp == ord_id)
																					{
																						ord_id++;
																						f = 0;

																					}
																					break;
																				}


																			}


																		}
																		ct++;

																	}
																	ct = 0;
																	while (getline(myfile_or, str_c))
																	{
																		if (ct == 0 || ct % 5 == 0)
																		{

																			for (int i = 0; i < str_c.length(); i++)
																			{
																				if (i == 4)
																				{
																					if (n_id == str[i])
																					{
																						fo = 0;
																						break;
																					}
																				}


																			}
																			if (fo == 0)
																			{
																				break;
																			}


																		}
																		ct++;

																	}
																	if (fo == 1)
																	{
																		f = 1;
																	}
																}
																else {
																	cout << " not";
																}

															}
															cout << "\norder id is:" << ord_id;
															pnn2->order_id = ord_id;
															myfile_o << "ID:" << " " << ord_id << endl;

															cout << "\n enter the id product that u choose:";
															cin >> pnn2->pro_id;
															//to check is the product available in the stock or not
															for (;;)
															{
																product* pcurr = NULL;
																pcurr = P.phead;
																int exisit = 0;

																while (pcurr != NULL)
																{
																	if (pnn2->pro_id == pcurr->pro_id && pcurr->quantity > 0)
																	{
																		exisit = 1;
																		break;
																	}

																	pcurr = pcurr->pnext;
																}
																if (exisit != 1)
																{
																	cout << "\n invalid product pls choose available one:";
																	cin >> pnn2->pro_id;
																}
																else
																{
																	break;
																}
															}
															myfile_o << "PID:" << pnn2->pro_id << endl;



															pnn2->cust_id = n_id;//the id of the costumer
															myfile_o << "CID:" << pnn2->cust_id << endl;



															cout << "\nenter the date: ";
															cin >> pnn2->date;
															// to check availability of the date ;
															for (;;)
															{

																if (pnn2->date > 30 || pnn2->date < 1)
																{
																	cout << "\n invalid date pls enter available one :";
																	cin >> pnn2->date;

																}
																else
																{
																	break;
																}



															}
															myfile_o << "DA:" << " " << pnn2->date << endl;



															//calculate the cart

															product* ptrav2 = P.phead;
															while (ptrav2 != NULL)
															{
																if (pnn2->pro_id == ptrav2->pro_id)
																{
																	pnn2->cart = ptrav2->price;
																	ptrav2->quantity--;

																}
																ptrav2 = ptrav2->pnext;
															}

															cout << " \n here is the cart :" << pnn2->cart;
															myfile_o << "CA:" << " " << pnn2->cart << endl;


															//UPDATE THE CHANGE OF QUANTITY AFTER EDDIT
															product* ptravv = NULL;
															ptravv = P.phead;
															ofstream myfile_po("product.txt");
															if (myfile_po.is_open()) {
																while (ptravv != NULL) {

																	myfile_po << "ID:" << " " << ptravv->pro_id << endl;



																	myfile_po << "NAME:" << " " << ptravv->pro_name << endl;


																	myfile_po << "quantity:" << " " << ptravv->quantity << endl;


																	myfile_po << "price:" << " " << ptravv->price << endl;


																	myfile_po << "expire_month:" << " " << ptravv->exp_m << endl;


																	myfile_po << "expire_year:" << " " << ptravv->exp_y << endl;
																	ptravv = ptravv->pnext;
																	myfile_po << endl;
																}
																myfile_po.close();
															}

															O.Attach(pnn2);
															myfile_o.close();
															myfile_or.close();




															int e;
															cin >> e;



														}
														// return order
														if (chose == 2)
														{

															system("cls");
															// to check if this customer take any order or not (this customer only)
															order* pcurr = NULL;
															pcurr = O.phead;
															int ct_order = 0;
															while (pcurr != NULL)
															{
																if (n_id == pcurr->cust_id)
																{
																	ct_order++;
																}

																pcurr = pcurr->pnext;
															}
															if (ct_order > 0)
															{

																cout << "\nsly 3la elnaby 34an enta gay 3lena b5sara" << endl;
																cout << "\nenter the order id which u want to return ya rais:";
																int u;
																cin >> u;// the order id which the customer choose 

																order* ptrav = NULL;
																ptrav = O.phead;
																while (ptrav != NULL)
																{
																	if (ptrav->order_id == u)
																	{

																		product* ptravvv = NULL;
																		ptravvv = P.phead;
																		while (ptravvv != NULL)
																		{
																			if (ptravvv->pro_id == ptrav->pro_id)
																			{
																				ptravvv->quantity++;
																			}

																			ptravvv = ptravvv->pnext;
																		}


																	}



																	ptrav = ptrav->pnext;
																}

																//UPDATE THE CHANGE OF QUANTITY AFTER EDDIT
																product* ptravv = NULL;
																ptravv = P.phead;
																ofstream myfile_po("product.txt");
																if (myfile_po.is_open()) {
																	while (ptravv != NULL) {

																		myfile_po << "ID:" << " " << ptravv->pro_id << endl;



																		myfile_po << "NAME:" << " " << ptravv->pro_name << endl;


																		myfile_po << "quantity:" << " " << ptravv->quantity << endl;


																		myfile_po << "price:" << " " << ptravv->price << endl;


																		myfile_po << "expire_month:" << " " << ptravv->exp_m << endl;


																		myfile_po << "expire_year:" << " " << ptravv->exp_y << endl;
																		ptravv = ptravv->pnext;
																		myfile_po << endl;
																	}
																	myfile_po.close();
																}
																//delete the order that the user have returned



																system("cls");

																ptrav = O.phead;
																order* pback = NULL;

																while (ptrav != NULL)
																{
																	if (ptrav->order_id == u)
																	{
																		if (pback == NULL)
																		{
																			O.phead = ptrav->pnext;
																		}
																		else
																		{
																			pback->pnext = ptrav->pnext;
																		}

																		delete ptrav;
																		cout << "Item with Id " << u << " deleted from list." << endl;
																		int c;
																		cin >> c;
																		break;
																	}
																	pback = ptrav;
																	ptrav = ptrav->pnext;
																}

																order* pcurr = NULL;
																pcurr = O.phead;
																ofstream myfile_co("order.txt");
																if (myfile_co.is_open()) {
																	while (pcurr != NULL)
																	{

																		myfile_co << "ID:" << " " << pcurr->order_id << endl;


																		myfile_co << "PID:" << pcurr->pro_id << endl;



																		pcurr->cust_id = n_id;//the id of the costumer
																		myfile_co << "CID:" << pcurr->cust_id << endl;



																		myfile_co << "DA:" << " " << pcurr->date << endl;
																		pcurr = pcurr->pnext;
																	}
																	myfile_po.close();
																}






																cout << "\n mtge4 tany !!!";
																int e;
																cin >> e;


															}
															else
															{
																cout << " \n u didn't take any orders to return !!!!";
																int r;
																cin >> r;
															}
														}
														//view the receipt
														if (chose == 3)
														{
															system("cls");
															order* ptrav = NULL;
															ptrav = O.phead;
															int tot = 0;
															while (ptrav != NULL)
															{

																if (ptrav->cust_id == n_id)
																{
																	cout << "\norderId:" << ptrav->order_id << endl << "productId:" << " " << ptrav->pro_id << endl << "date of order:" << ptrav->date << "/1/2024" << endl << endl;

																	tot += ptrav->cart;
																}
																ptrav = ptrav->pnext;
															}
															cout << "\n here is  the whole receipt sir:" << tot;
															int t;
															cin >> t;
														}
														//exit
														if (chose == 4)
														{
															break;

														}



													}
												}

											}
											if (y != 0) {
												y--;
											}
										}
										else
										{
											break;
										}
									}
								}
							}
							ct++;
						}
						int k;
						cin >> k;
						break;
					}
					else
					{
						cout << "not";
					}
				}
				int r;
				cin >> r;


			}
		}
		if (AC == 3)
		{
			break;
		}

		system("cls");

	}



}