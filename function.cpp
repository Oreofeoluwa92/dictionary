#include "header.hpp"

WORD getNextWord(std::ifstream &file) {
    WORD w; 
    char ch;
    bool inWord = false; 
    while (file.get(ch)) {
        if (isalpha(ch)) { 
        w.push_back(ch); inWord = true;
        } else if (inWord) { 
            return w; 
            
        }
        }
        return w; 
    
} 
bool isValidWord(const std::string& word) {
    // Returns true if all characters in the word are alphabetic
    return std::all_of(word.begin(), word.end(), [](char ch) {
        return std::isalpha(static_cast<unsigned char>(ch));
    });
}
        void buildDictionary(DICTION& d) { 
    std::ifstream file("input.txt"); // Replace "input.txt" with your file name
    if (!file) { 
        std::cerr << "Error opening file" << std::endl; 
        return; 
    } 

    d = DICTION(); // Reset the dictionary structure
    char ch;
    WORD word;

    // First pass: Count characters, lines, and letter frequencies
    while (file.get(ch)) { 
        // Count total characters
        std::get<0>(d.stats)++; 

        // Count lines
        if (ch == '\n') { 
            std::get<2>(d.stats)++; 
        } 

        // Count letter frequencies (only alphabetic characters)
        if (std::isalpha(ch)) { 
            d.wordFreq[(ch)]++; 
        } 
    } 

    file.clear(); 
    file.seekg(0); // Reset file pointer for word processing

    // Second pass: Process words
    while (file >> word) { 
        // Convert to lowercase
      //  std::transform(word.begin(), word.end(), word.begin(), ::tolower);  

        // Check if the word is valid (contains only alphabetic characters)
        if (std::all_of(word.begin(), word.end(), [](char c) { 
            return std::isalpha(c); })) { 
            // Increment word count
            std::get<1>(d.stats)++; 

            // Add to unique words set
            d.words.insert(word); 

            // Update word frequency map
            d.freqWord.insert({word.length(), word}); 

            // Add word to the priority queue (longest words)
            d.longWord.push(word); 
        } 
    } 

    file.close(); 
}


void showStats(const DICTION& d) {
    std::cout << "Words in dictionary – ";
    bool first = true;
    for (const auto& word : d.words) {
        if (!first) std::cout << ", ";
        std::cout << word;
        first = false;
        
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    

    std::cout << "Number of Letters : " << std::get<0>(d.stats) << std::endl;
    std::cout << "Number of Words : " << std::get<1>(d.stats) << std::endl;
    std::cout << "Number of Lines : " << std::get<2>(d.stats) << std::endl;
    std::cout << std::endl;
    
}




void drawHistograms(const DICTION& d) {
    std::cout << "/--------------\\" << std::endl;
    std::cout << "| Letter Freq |" << std::endl;
    std::cout << "\\--------------/" << std::endl;
    
    
     for (char c = 'a'; c <= 'z'; c++) {
     char upper_c = toupper(c); // Convert lowercase letter to uppercase
    auto it_upper = d.wordFreq.find(upper_c);
    std::cout << upper_c << " | "; // Print uppercase letter
    if (it_upper != d.wordFreq.end()) {
        int stars = std::min(it_upper->second, 10);  // Limit the stars to a maximum of 10
        std::cout << std::string(stars, '*'); // Print the stars for the frequency
        if (it_upper->second > 10) { // Print the extra frequency in parentheses if > 10
            std::cout << " (" << it_upper->second << ")";
        }
    }
    std::cout << std::endl; // End of the line for the lowercase letter
    std::cout << std::endl;
     }
   for (char c = 'a'; c <= 'z'; c++) {
    // Handle lowercase letters
    auto it_lower = d.wordFreq.find(c);
    std::cout << c << " | "; // Print lowercase letter
    if (it_lower != d.wordFreq.end()) {
        int stars = std::min(it_lower->second, 10);  // Limit the stars to a maximum of 10
        std::cout << std::string(stars, '*'); // Print the stars for the frequency
        if (it_lower->second > 10) { // Print the extra frequency in parentheses if > 10
            std::cout << " (" << it_lower->second << ")";
        }
    }
   
   
    std::cout << std::endl; 
    std::cout << std::endl;
}


    std::cout << "/------------\\" << std::endl;
    std::cout << "| Dictionary |" << std::endl;
    std::cout << "\\------------/" << std::endl;
    std::cout << std::endl;
    std::cout << "Word      Frequency" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (const auto& pair : d.words) {
       int frequency = d.wordFreq.at(pair[0]);
cout << std::left <<setw(12) << pair << " " << frequency << std::endl;
  }
    

    std::cout << "/------------\\" << std::endl;
    std::cout << "| Histogram |" << std::endl;
    std::cout << "\\------------/" << std::endl;
    std::cout << std::endl;

    for (const auto& entry : d.freqWord) {
        std::cout << entry.second << " ";
        for (int i = 0; i < entry.first; ++i) std::cout << "*";
        std::cout << std::endl;
    }

   /* int max_freq = freq_to_words.rbegin()->first;
    for (int i = max_freq; i > 0; --i) {
        for (const auto& pair : freq_to_words) {
            if (pair.first >= i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }*/
    WORD_FREQ_LIST freq_to_words;

    cout << WORD(freq_to_words.size(), '-') << std::endl;
    for (const auto& pair : freq_to_words) {
        std::cout << "^";
    }
    cout << std::endl;

    for (const auto& pair : freq_to_words) {
        cout << pair.second << std::string(std::to_string(pair.second).length(), '-');
    }
    std::cout << std::endl;
}
