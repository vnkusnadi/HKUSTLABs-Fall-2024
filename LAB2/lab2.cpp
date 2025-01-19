#include <iostream>
using namespace std;

int main()
{
    // m1 - number of missionaries at bank 1
    // c1 - number of cannibals at bank 1
    // m2 - number of missionaries at bank 2
    // c2 - number of cannibals at bank 2
    // b - boat position (1 or 2)
    // lose - a boolean to indicate whether missionaries are eaten
    // Initial state: 3 missionaries and 3 cannibals at bank 1, 0 missionaries and 0 cannibals at bank 2, boat at bank 1
    int m1 = 3, c1 = 3, m2 = 0, c2 = 0, b = 1;
    bool lose = false;
    int m_move, c_move;

    // ----------------------------------------------
    // Task 1: Winning condition
    // When the winning condition is not met, continue the game
    while (c2 + m2 < 6)
    // ----------------------------------------------
    {
        // Print the current state before each move
        cout << "Bank 1: " << m1 << " missionaries, " << c1 << " cannibals" << endl;
        cout << "Bank 2: " << m2 << " missionaries, " << c2 << " cannibals" << endl;
        cout << "Boat is at bank " << b << endl;

        // ------------------------------------------------------------------------
        // Task 2: Input and move
        // Read the number of missionaries and cannibals to move and update relevant
        // variables. Read missionaries first and then cannibals. You also need to
        // output the prompt, so put the following two "cout" statements to
        // appropriate places.

        // cout << "Enter the number of missionaries to move: ";
        // cout << "Enter the number of cannibals to move: ";

        // You don't need to validate the input, which means you may assume:
        // 1. The input is never negative
        // 2. The input is no larger than the number of missionaries or cannibals at the bank
        // 3. The number of people on board is always between 1 and 2
        // Our demo programs provide input validation. If you are interested, you can also try
        // to validate the input yourself, but this won't be tested in ZINC testcases.

        // However, it is POSSIBLE that an input leads to a losing condition (missionaries eaten)

        // YOUR CODE HERE
        // ------------------------------------------------------------------------

        if (b == 1)
        {
            cout << "Enter the number of missionaries to move: ";
            cin >> m_move;
            m1 = m1 - m_move;
            m2 = m2 + m_move;

            cout << "Enter the number of cannibals to move: ";
            cin >> c_move;
            c1 = c1 - c_move;
            c2 = c2 + c_move;

            b = 2;
        }
        else if (b == 2)
        {
            cout << "Enter the number of missionaries to move: ";
            cin >> m_move;
            m2 = m2 - m_move;
            m1 = m1 + m_move;

            cout << "Enter the number of cannibals to move: ";
            cin >> c_move;
            c2 = c2 - c_move;
            c1 = c1 + c_move;

            b = 1;
        }

        // ----------------------------------------------------------------------------
        // Task 3: Losing condition
        // If the losing condition is met after a move, set "lose" to true and then break
        // the loop to stop the game

        // YOUR CODE HERE
        // ----------------------------------------------------------------------------
        if ((c2 > m2 && m2 != 0) || (c1 > m1 && m1 != 0))
        {
            lose = true;
            break;
        }

        // ----------------------------------------------------------------------------
    }

    // Print the final state
    cout << "Bank 1: " << m1 << " missionaries, " << c1 << " cannibals" << endl;
    cout << "Bank 2: " << m2 << " missionaries, " << c2 << " cannibals" << endl;
    if (lose)
    {
        cout << "Missionaries been eaten! Game over!" << endl;
    }
    else
    {
        cout << "You win!" << endl;
    }

    return 0;
}
