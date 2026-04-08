all:
	make clothing
	make authenticate
	make user
	g++ clothing.o auth.o user.o main.cpp -o ForecastFits

clothing: Clothing.cpp Clothing.h
	g++ -c Clothing.cpp -o clothing.o

authenticate: AuthSystem.cpp AuthSystem.h UserProfile.h
	g++ -c AuthSystem.cpp -o auth.o

user: UserProfile.cpp UserProfile.h Closet.h Clothing.h
	g++ -c UserProfile.cpp -o user.o

clean:
	rm -f ForecastFits clothing.o auth.o user.o