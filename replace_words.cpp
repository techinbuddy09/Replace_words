class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>root_words;// map containing dictionary root words
        // iterating in the map
        for( auto it: dictionary) // range based loop (vectors)

        {
            root_words[it]=1;// means we will traverse it in setting a pair and key =1..ex(cat,1)(bat,1)(rat,1)
        }
        string result="";// empty storing final sentence with replaced rootwords
        string word="";// empty string conating each characters..one by one checking for rootword
        bool present=false;// a boolean which is itnitially at false becomes true if ..rootword present
        // loop to iterate over each charcters  in the sentence and check for rootword
        for(int i=0;i<sentence.length();i++)
        {
           // if the current word has  space so it will  store the root word if present to result vector ..
            // if no space then it will add the current charcter to the sentence  
            // example= the 
        // word= t
            // prsent  false
            // second time...// word=th  present=false  // word=the..present=true..
             if(sentence[i]==' ') // if the current word has a space 
               {
                    if(present==false){ // means we reached the space and present is still false means no root word present 
                     result+=word; // we will simply add the word to the final string
                     result+=" ";// for adding space after one word 
               }
             
                word=""; // and again set it at initial position
                present=false; // again set at false
             }
            
            else
            {
                word=word+sentence[i];// we wil add the  word to the sentence and set prsent at false ;
                if(root_words[word]==1&&present==false) // check if present in map [cat,1] so ==1 
                {
                    result+=word; // then add to it
                    result+=" "; // and leave space
                    present=true;
                }
                
            }
        }
     
        // these cases may occur in the end ..in last word
       if(present==false) // in the last if no root word .. so then no space for that case
           // just aff it to the word without saoce ..like battery 
        {
                   result+=word; // then add to it
                
       }
        else
        {
        
        result.pop_back();// and if suppose rootword present like(bat,1).. so just pop that word to last position in the vector no ne
            // avoiding the case of extra space
        
        }
        return result;// final modified string
        
    }
};
