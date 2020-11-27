struct patient
{
    char name[255];
    int day;
    char month[255];
    int year;
};
struct Node
{
    patient a;
    Node *next, *prev;
} * head, *tail, *curr;

const char january = 1;
const char february = 2;
const char march = 3;
const char april = 4;
const char may = 5;
const char june = 6;
const char july = 7;
const char august = 8;
const char september = 9;
const char october = 10;
const char november = 11;
const char december = 12;
