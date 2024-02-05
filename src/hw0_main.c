#include <stdio.h>

void print_game(int game[]) {
    printf("%d %d %d %d | %d\n", game[0], game[1], game[2], game[3], game[4]);
}

int main() {
    int game[5] = {2,2,2,2,0};
    int game_over = 0;
    int input;
    print_game(game);
    while (game_over == 0) {
        printf("Choose a section (1-4): ");
        scanf("%d", &input);

        while (input < 1 || input > 4 || game[input - 1] == 0) {
            printf("Invalid choice. Choose a section (1-4): ");
            scanf("%d", &input);

        }
        int current_section = input - 1;
        int seeds_in_hand = game[current_section];
        game[current_section++] = 0;

        for (int i = seeds_in_hand; i > 0; i--) {
            game[current_section]++;
            if (i > 1) current_section++;
            if (current_section > 4) current_section = 0;
                   
        }
        print_game(game);

        while (current_section <= 3) {
            if (game[current_section] > 1) {
                printf("Last piece landed in section %d. Continue sowing seeds!\n", current_section + 1);
                seeds_in_hand = game[current_section];
                game[current_section++] = 0;

                for (int i = seeds_in_hand; i > 0; i--) {
                    game[current_section]++;
                    if (i > 1) current_section++;
                    if (current_section > 4) current_section = 0;
                    
                }
                print_game(game);

            } else {
                printf("You lost because the last counter fell into section %d.\n", current_section + 1);
                game_over = 1;
                break;
            }
        }

        if (game[4] == 8) {
            printf("You won!\n");
            game_over = 1;
        }

        

    }
    
    



    


    
    return 0;
}

