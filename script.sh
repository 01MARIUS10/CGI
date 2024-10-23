g++ -Wall ./userLists.cpp  ./Entity/**/*.cpp  ./Service/**/*.cpp  ./Request/*.cpp  ./View/**/**/*.cpp  -o userLists.cgi &&
g++ -Wall ./Api/user_action.cpp  ./Entity/**/*.cpp  ./Service/**/*.cpp  ./Request/*.cpp  ./View/**/**/*.cpp  -o user_action.cgi &&
g++ -Wall ./Api/user_register.cpp  ./Entity/**/*.cpp  ./Service/**/*.cpp  ./Request/*.cpp  ./View/**/**/*.cpp  -o user_register.cgi &&
g++ -Wall ./userEdit.cpp  ./Entity/**/*.cpp  ./Service/**/*.cpp  ./Request/*.cpp  ./View/**/**/*.cpp  -o userEdit.cgi &&

cp user_action.cgi ./Api &&
cp user_register.cgi ./Api &&
sudo cp -R ./* /var/www/SITE/site3 &&
rm ./*.cgi ./Api/*.cgi && 
chown -R www-data:www-data /var/www/SITE/site3/* &&
echo "success"