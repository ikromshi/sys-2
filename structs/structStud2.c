#include <stdio.h>
#include <string.h>

// Define a new type: struct studentT
// Note that struct definitions should be outside function bodies.
struct studentT {
    char name[64];
    int age;
    float gpa;
    int grad_yr;
};

/* function prototype (prototype: a declaration of the
 *    checkID function so that main can call it, its full
 *    definition is listed after main function in the file):
 */
int checkID(struct studentT s1, int min_age);

int main() {
    int can_vote;
    struct studentT student;

    strcpy(student.name, "Kwame Salter");  // name field is a char array
    student.age = 17;                  // age field is an int
    student.gpa = 3.5;                     // gpa field is a float
    student.grad_yr = 2024;                // grad_yr field is an int

    /* Note: printf doesn't have a format placeholder for printing a
     * struct studentT (a type we defined).  Instead, we'll need to
     * individually pass each field to printf. */
    printf("name: %s age: %d gpa: %g, year: %d\n",
           student.name, student.age, student.gpa, student.grad_yr);

    can_vote = checkID(student, 18);
    if (can_vote){
      printf("%s is %d years old and can vote.\n", student.name, student.age);
    }else{
      printf("%s is only %d years old and cannot vote.\n", student.name, student.age);
    }

    return 0;
}

/*  check if a student is at least the min age
 *    s: a student
 *    min_age: a minimum age value to test
 *    returns: 1 if the student is min_age or older, 0 otherwise
 */
int checkID(struct studentT s, int min_age)
{
    int ret = 1;  // initialize the return value to 1 (true)
    if(s.age < min_age) {
        ret = 0;  // update the return value to 0 (false)
        // let's try changing the student's age
        s.age = min_age + 1;
    }
    printf("%s is %d years old\n", s.name, s.age);
    return ret;
}
