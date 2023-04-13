CC = g++
app: app.cpp Registrar.cpp Course.cpp Student.cpp Day.cpp Schedule.cpp Utils.cpp Roster.cpp
	$(CC) -o app.exe Registrar.cpp app.cpp Course.cpp Utils.h Student.cpp Day.cpp Schedule.cpp Utils.cpp Roster.cpp -I.

random: randomData.cpp Course.cpp Student.cpp Day.cpp Schedule.cpp Utils.cpp Roster.cpp
	$(CC) -o ran.exe randomData.cpp Course.cpp Utils.h Student.cpp Day.cpp Schedule.cpp Utils.cpp Roster.cpp -I.

clean:
	rm -f *.exe