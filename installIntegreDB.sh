BOLD="\e[1m"
RESET="\e[0m"
RED="\e[31m"


Install_Postgresql()
{
 echo -e "\nInstalling IntegreDB PostGres Server..."
# sudo apt update
# sudo apt install -y postgresql postgresql-contrib
 echo -e "\n${RED}Installation Complete Sucessfully.${RESET}"
}

PostGres_PostGis()
{
# sudo apt update
 Install_Postgresql
 Postgis
}

Postgis()
{
 echo -e "\nInstalling IntegreDB PostGis extension..."
# sudo apt update
# sudo apt install -y postgresql postgresql-contrib postgis
 echo -e "\n${RED}Installation Complete Sucessfully.${RESET}"
}

count=0
\clear
echo -e "\n\n\n"
cat image.txt
while [ $count -ne 5 ];do
echo
echo -e "\n\tYou are about to install IntegreDB Server,\n\tBelow is the licensing, Terms and condition for the same, than you can shoose the below option"
echo -e "\n1)IntegreDB Postgres Server"
echo -e "2)Server Along with extension PostGis"
echo -e "3)PostGis"
echo
read -p "Enter Choice : " choice

case $choice in
	1)
        	Install_Postgresql
		break
		;;
	2)
		PostGres_PostGis
		break
		;;
	3)
		Postgis
		break
		;;
	*)
		if [ $count -le 5 ];then
			((count++))
			echo -e "\n${RED}Invalid argument.Try again${RESET}"
			continue;
		fi
		exit
		;;
esac
done


if [ $count -eq 5 ];then
	 exit
fi
	
echo -e "\nEnabling and starting PostgresSql service..."
#sudo systemctl enable postgresql
#sudo systemctl start postgresql
echo -e "\nConfiguring PostgreSql for local access"
echo -e "\nPlease Enter Password for Security change for 'postgres' user."
read -s -p "Password : " passwrd
#sudo -s postgres sql  -c "ALTER USER postgres PASSWORD '${passwrd}';"
echo -e "\n\n${RED}PostgreSQL has been configured with a default password for the 'postgres' user.${RESET}"
echo -e "\n${BOLD}Thanks for using IntegreDB Server application :)${RESET}"
