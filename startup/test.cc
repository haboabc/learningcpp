#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
	Sales_item total, item;
	
	// 输入第一个item, 用于初始化total 
	if (cin >> item) {
		total = item;	
		
		while (cin >> item || !(cerr << "Invalued item" << endl)) {
			/* item is valued */
			if (total.same_isbn(item)) {
				/* same isbn with before */	
				total += item;
			} else {
				/* different isbn from before*/	
				cout << total << endl;
				total = item;
			}	
		}

	} else {
		/* no item */	
		cerr << "NO inpute" << endl;
	} 

	/* the last item */
	cout << total << endl;

	return 0;
}
