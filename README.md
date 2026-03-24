# Secret-Santa-Generator
A bash script that randomly generates partners for every person in a list and outputs them in separate text files for confidentiality.

This program takes a number on the first line as the number of people that you 
want to input, and then the names of each person on the following lines. Each 
person's Secret Santa partner will be outputted in the "partners" folder, with 
the filename "Name.txt" and the content "Name, your partner is PartnerName".

The script automatically cleans up the text files in "partners", so make sure
to save the data elsewhere if you don't want to lose it before running the
script again.

You may need to give the secret.sh script execution permissions with chmod +x ./secret.sh.
