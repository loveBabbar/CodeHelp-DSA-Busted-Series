public static String replaceSpaces(String str){
	String temp = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str.charAt(i) == ' '){
            temp += '@';
            temp += '4';
            temp += '0';
        }
        else
        {
            temp += str.charAt(i);
        }
    }
    return temp;
}
