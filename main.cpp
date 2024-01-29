#include <iostream>
#include <cstdlib>
#include <ctime>

enum class Choice { ROCK, PAPER, SCISSORS };

class RockPaperScissors {
public:
    RockPaperScissors() {
        srand(static_cast<unsigned>(std::time(0)));
    }

    void playGame() {
        while (true) {
            displayMenu();
            Choice userChoice = getUserChoice();
            Choice computerChoice = getComputerChoice();

            std::cout << "Bilgisayarın seçimi: " << choiceToString(computerChoice) << std::endl;

            if (userChoice == computerChoice) {
                std::cout << "Berabere!" << std::endl;
            }
            else if (isUserWin(userChoice, computerChoice)) {
                std::cout << "Tebrikler, kazandınız!" << std::endl;
            }
            else {
                std::cout << "Üzgünüm, kaybettiniz. Tekrar deneyin." << std::endl;
            }

            if (!playAgain()) {
                break;
            }
        }
    }

private:
    void displayMenu() const {
        std::cout << "1. Taş\n";
        std::cout << "2. Kağıt\n";
        std::cout << "3. Makas\n";
    }

    Choice getUserChoice() const {
        int choice;
        do {
            std::cout << "Lütfen bir seçenek girin (1-3): ";
            std::cin >> choice;
        } while (choice < 1 || choice > 3);

        return static_cast<Choice>(choice - 1);
    }

    Choice getComputerChoice() const {
        return static_cast<Choice>(rand() % 3);
    }

    bool isUserWin(Choice user, Choice computer) const {
        return (user == Choice::ROCK && computer == Choice::SCISSORS) ||
            (user == Choice::PAPER && computer == Choice::ROCK) ||
            (user == Choice::SCISSORS && computer == Choice::PAPER);
    }

    std::string choiceToString(Choice choice) const {
        switch (choice) {
        case Choice::ROCK: return "Taş";
        case Choice::PAPER: return "Kağıt";
        case Choice::SCISSORS: return "Makas";
        default: return "Geçersiz";
        }
    }

    bool playAgain() const {
        char response;
        std::cout << "Tekrar oynamak istiyor musunuz? (e/E: Evet, h/H: Hayır): ";
        std::cin >> response;
        return (response == 'e' || response == 'E');
    }
};

int main() {
    setlocale(LC_ALL, "turkish");
    
    RockPaperScissors game;
    game.playGame();

    return 0;
}
