
//Author:S.Thameem Ansari#include <stdio.h>
int defendCastle(int castle_people[], int num_castle_people, int soldiers[], int num_soldiers) {
    

    int soldier_index = 0;
    int castle_people_index = 0;

    while (soldier_index < num_soldiers && castle_people_index < num_castle_people) {
        if (soldiers[soldier_index] >= castle_people[castle_people_index]) {
            // A soldier can defeat an invader
            soldier_index++;
            castle_people_index++;
        } else {
            // If the soldier is weaker than the invader, they cannot participate in the battle
            soldier_index++;
        }
    }
    if (castle_people_index == num_castle_people) {
        // All enemy soldiers have been defeated
        int remaining_soldier_power = 0;
        for (int i = soldier_index; i < num_soldiers; i++) {
            remaining_soldier_power += soldiers[i];
        }
    printf("Remaining soldiers power who left defend %d\n",remaining_soldier_power);
        return remaining_soldier_power;
    } else {
        // Castle people have to defend as a last resort
        int castle_people_needed = num_castle_people - castle_people_index;
         printf("number of castle people left %d\n",castle_people_needed);
        return castle_people_needed;
    }
}

int main() {
    int  castle_people[] = {10, 7, 4, 5, 3, 2};
    int num_castle_people = sizeof(castle_people)/sizeof(castle_people[0]);
    //the castle people and soldier are equal or soldier are greater then castle people
    int soldiers[] = {62,19,11,23,13,9,16};
    int num_soldiers = sizeof(soldiers)/sizeof(soldiers[0]);;

    int result = defendCastle(castle_people, num_castle_people, soldiers, num_soldiers);
   
    return 0;
}
