/* This program will play rock, paper, scissors,
 lizard, spock with you */

#include <iostream>

const char* int_to_pick(int a) {
  switch (a){
    case 1:
        return "rock";
    case 2:
        return "paper";
    case 3:
        return "scissors";
    case 4:
        return "spock";
   case 5:
      return "lizard";
  }
}

const char* description(int a, int b) {
  if ((a == 1 and b == 2) or (a == 2 and b == 1)){
    return "Paper covers rock.";
  }
  else if ((a == 1 and b == 3) or (a == 3 and b == 1)) { 
    return "Rock smashes scissors.";
  } else if ((a == 1 and b == 4) or (a == 4 and b == 1)) {   
    return "Spock vaporizes rock.";
  } else if ((a == 1 and b == 5) or (a == 5 and b == 1)) {   
    return "Lizard posions Spock.";
  } else if ((a == 2 and b == 3) or (a == 3 and b == 2)) {   
    return "Scissors cut paper.";
  } else if ((a == 2 and b == 4) or (a == 4 and b == 2)) {   
    return "Paper disproves Spock.";
  } else if ((a == 2 and b == 5) or (a == 5 and b == 2)) {   
    return "Lizard eats paper.";
  } else if ((a == 3 and b == 4) or (a == 4 and b == 3)) {   
    return "Spock crushes scissors.";
  } else if ((a == 3 and b == 5) or (a == 5 and b == 3)) {   
    return "Scissors decapitate lizard.";
  } else if ((a == 4 and b == 5) or (a == 5 and b == 4)) {   
    return "Lizard poisons Spock.";
  } else {
    return "Catastrophic ERROR!";
  }
}


int game(){
  srand (time(NULL));
  int computer = rand()%5 + 1;
  int user = 0;
  int play_again;
  //string winner;
  // Live long and prosper
  std::cout << "=================================\n";
  std::cout << "rock paper scissors lizard spock!\n";
  std::cout << "=================================\n";

  std::cout << "1) ✊\n";
  std::cout << "2) ✋\n";
  std::cout << "3) ✌️\n";
  std::cout << "4) 🖖\n";
  std::cout << "5) 🦎\n";

  std::cout << "shoot! ";
  do {
    std::cin >> user;
  } while (user < 0 or user > 5);
  const char *user_pick = int_to_pick(user);
  const char *computer_pick = int_to_pick(computer);
  std::cout << "You pick "
            << user_pick;
  std::cout << "\n";
  std::cout << "Computer picks "
            << computer_pick
            << "\n";
  const char *win_text = description(user, computer);

  int compare = user - computer + 5;

  if (compare%5 == 0) {
    std::cout << "It's a tie!\n";
  }
  else if ((compare%5 +1)%2 == 0) {
    std::cout << win_text << "\n";
    std::cout << "You win!\n";
  }
  else if ((compare%5)%2 == 0) {
    std::cout << win_text << "\n";
    std::cout << "The computer wins!\n";
  }
  std::cout << "Do you wish to play again?\n"
            << "1) Yes.\n"
	    << "2) No.\n";
  do {
    std::cin >> play_again;
  } while (play_again != 1 and play_again != 2);

  return play_again;
}

int main() {
  int cont = 1;
  
  do {
    cont = game();
  } while (cont == 1);

  std::cout << "\nGoodbye!\n";

  return 0;
}
