#include <stdio.h>
#include <stdlib.h>
#include "cgi.h"

// Helper macro to convert two-character hex strings to character value
#define ToHex(Y) (Y>='0'&&Y<='9'?Y-'0':Y-'A'+10)

void getAllParams() {
// Determing if it is a POST or GET method
if( getenv( "REQUEST_METHOD" ) == 0 ) {
printf("No REQUEST_METHOD, must be running in DOS mode");
return;
} else if (strcmp( getenv("REQUEST_METHOD"), "POST") == 0) {
// If POST
char *endptr; // quite useless, but required
char *len1 = getenv("CONTENT_LENGTH");
int contentlength = strtol(len1, &endptr, 10);
fread(InputData , contentlength, 1, stdin);
} else {
// If GET
strcpy(InputData, getenv("QUERY_STRING"));
}
}

void getParam(const char *Name, char *Value) {
char *pos1 = strstr(InputData, Name);

if (pos1) {
pos1 += strlen(Name);

if (*pos1 == '=') { // Make sure there is an '=' where we expect it
pos1++;

while (*pos1 && *pos1 != '&') {
if (*pos1 == '%') { // Convert it to a single ASCII character and store at our Valueination
*Value++ = (char)ToHex(pos1[1]) * 16 + ToHex(pos1[2]);
pos1 += 3;
} else if( *pos1=='+' ) { // If it's a '+', store a space at our Valueination
*Value++ = ' ';
pos1++;
} else {
*Value++ = *pos1++; // Otherwise, just store the character at our Valueination
}
}

*Value++ = '\0';
return;
}

}

strcpy(Value, "undefine"); // If param not found, then use default parameter
return;
}


int test_main() {

char myName[100] = "";
char myAddress[100] = "";

printf("Content-Type:text/html \n\n");
getAllParams();
getParam("Name", myName);
getParam("Address", myAddress);

printf("QueryString: %s", InputData);
printf("<br>");
printf("Name: %s", myName);
printf("<br>");
printf("Address: %s", myAddress);


return 0;
} 
