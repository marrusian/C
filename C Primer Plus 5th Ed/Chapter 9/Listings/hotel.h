#define QUIT     5
#define HOTEL1   180.00
#define HOTEL2   225.00
#define HOTEL3   255.00
#define HOTEL4   355.00
#define DISCOUNT 0.95
#define STARS "******************************"

// shows list of choices
void menu(void);

// input validation for menu entry
int get_code(void);

// returns number of nights desired
int get_nights(void);

// calculates price from rate, nights
// and displays result
void show_price(double rate, int nights);