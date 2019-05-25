/*
 * Author : Jatin Rohilla
 * Date   : 21-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/justified-text/
 */


#include<bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> sentences;

    // arrange words
    int wordIndex = 0;
    string word;
    while(wordIndex < words.size()){
        word = words[wordIndex++];
        while(wordIndex < words.size() && (word.length() + 1 + words[wordIndex].length()) <= L){
            word += " " + words[wordIndex++];
        }
        sentences.push_back(word);
    }

    // add spaces
    int noOfGaps, totalSpacesRequired, oddSpacesUpto, evenSpaces, requiredSpaces;
    for(int i=0; i<sentences.size(); ++i){
        word = sentences[i];

        totalSpacesRequired = (L - word.length());
        if(totalSpacesRequired == 0){   continue;   }

        noOfGaps = 0;
        for(int j=0; j<word.length();++j){
            if(word[j]==' '){
                noOfGaps++;
            }
        }

        if(noOfGaps == 0 || i+1==sentences.size()){
            word.insert(word.length(), totalSpacesRequired, ' ');
            sentences[i] = word;
            continue;
        }

        evenSpaces = totalSpacesRequired/noOfGaps;
        oddSpacesUpto = totalSpacesRequired - (evenSpaces*noOfGaps);

        int wordNumber = 0;
        for(int j=0; j<word.length();++j){
            if(word[j]==' '){
                wordNumber++;
                requiredSpaces = evenSpaces + (wordNumber <= oddSpacesUpto ? 1 : 0);
                word.insert(j, requiredSpaces, ' ');
                j += requiredSpaces;
            }
        }

        sentences[i] = word;
    }

    // for(auto it : sentences){
    //     cout << "{" << it << "}:{"<<it.length()<<"}" << " ";
    // }
    return sentences;
}


int main(){

//	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
//	int L = 16;
//	vector<string> sentences =fullJustify(words, L);
//    for(auto it : sentences){
//        cout << "{" << it << "}:{"<<it.length()<<"}" << "\n";
//    }
    
//    cout << "\n\n";
//
//	vector<string> words = { "tv", "izln", "dkq", "ypbbix", "k", "xoojn", "xju", "xfe", "aysz", "agkfhvtqkt", "rsklvgn", "kedzohp", "lqzz", "hivu", "gtxrjj", "nz", "ysoatq", "n", "ote", "xuctw", "vlvgmfzm", "zlpmp", "oe", "kayhyihc", "yvsllceili", "osqkjjvydc", "p", "zxqrgyvnic", "ebxhww", "pyjdlt", "ruwl", "lnlt", "ddzf", "jicwez", "mcrj", "unbej", "on", "thivo", "sbzxsxvm", "jj", "lacb", "qfsopsmeq", "ial", "tifiuf", "uybh", "pcbufc", "nccdldzs", "pbsofijlmp", "ehdcxkgbi", "wu", "gvnzmw", "czonuzrls", "blg", "y", "qbdgiwboi", "wpeupcwz", "fxnbh", "sybikok", "ukuztzdqk", "oowhjnhol", "s", "kvmtoutvf", "ilh", "q", "tclbqcdbz", "oglfrq", "cwtucyecf", "am", "kflhesgk", "xnxpogj", "nx", "hwfb", "htmf", "xawcimlx", "hhivdgf", "uk", "evtsczh"};
//	int L = 483;
//	vector<string> sentences =fullJustify(words, L);
//    for(auto it : sentences){
//        cout << "{" << it << "}:{"<<it.length()<<"}" << "\n";
//    }
//    
    cout << "\n\n";
    vector<string> words = {"am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy" };
    int L = 14;
    vector<string> sentences =fullJustify(words, L);
    for(auto it : sentences){
        cout << "{" << it << "}:{"<<it.length()<<"}" << "\n";
    }

	return 0;
}

