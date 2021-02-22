#include <iostream>
#include <string>
#include <vector>

int main()
{
    bool next_seq = true;
    bool go_for_it = true;
    bool got_it = false;

    int num_tries = 0;
    int num_right = 0;

    double usr_score = 0.0;

    const int seq_size = 18;
    int elem_vals[seq_size] = 
    {
        1, 2, 3, 
        3, 4, 7, 
        2, 5, 12, 
        3, 6, 10, 
        4, 9, 16, 
        5, 12, 22
    };

    std::vector<int> elem_seq(elem_vals, elem_vals + seq_size);

    const int max_seq = 6;
    std::string seq_names[max_seq] = 
    {
        "Fibonacci", 
        "Lucas", 
        "Pell", 
        "Triangular", 
        "Square", 
        "Pentagonal"
    };

    int cur_tuple = 0;

    while (next_seq && (cur_tuple < seq_size))
    {
        std::cout << "The first two elements of the sequence are: "
                    << elem_seq[cur_tuple] << ", "
                    << elem_seq[cur_tuple + 1] << std::endl
                    << "What is the next element? ";

        while (!got_it && go_for_it)
        {
            int usr_guess;
            std::cin >> usr_guess;
            ++num_tries;

            if (usr_guess == elem_seq[cur_tuple + 2])
            {
                got_it = true;
                ++num_right;

                std::cout << "Very good. Yes, "
                        << elem_seq[cur_tuple + 2]
                        << " is the next element in the "
                        << seq_names[cur_tuple / 3]
                        << " sequence. " << std::endl;
            }
            else
            {
                switch (num_tries)
                {
                    case 1:
                        std::cout << "Oops! Nice guess but not quite it. " << std::endl;
                        break;
                    case 2:
                        std::cout << "Hmm. Sorry. Wrong a second time. " << std::endl;
                        break;
                    case 3:
                        std::cout << "Ah, this is harder than it looks, isn't it? " << std::endl;
                        break;
                    default:
                        std::cout << "It must be getting pretty frustrating by now! " << std::endl;
                        break;
                }

                std::cout << "Would you like to try again? (Y/N) ";
                char usr_rsp;
                std::cin >> usr_rsp;

                if (usr_rsp == 'N' || usr_rsp == 'n')
                {
                    go_for_it = false;
                }
            }
        }

        std::cout << "Want to try another sequence? (Y/N) ";
        char try_again;
        std::cin >> try_again;

        if (try_again == 'N' || try_again == 'n')
        {
            usr_score = ((double) num_right) / num_tries;

            std::cout << "Your score for this session is "
                    << usr_score 
                    << " Bye! " << std::endl;

            next_seq = false;
        }
        else
        {
            cur_tuple += 3;

            next_seq = true;
            go_for_it = true;
            got_it = false;

            num_tries = 0;
            num_right = 0;
        }
    }
}