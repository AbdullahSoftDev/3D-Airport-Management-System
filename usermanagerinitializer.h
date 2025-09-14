#ifndef USERMANAGERINITIALIZER_H
#define USERMANAGERINITIALIZER_H
#include "AppPaths.h" // Include AppPaths header
#include <QString> // Required for QString

// This class will handle checking and initializing the users.csv file.
class UserManagerInitializer
{
public:
    // Static method to initialize the users.csv file.
    // It's static because you don't need to create an object of this class
    // to call this function.
    static void initializeUsersFile();

private:
    // Private constructor to prevent instantiation, as it's a utility class.
    UserManagerInitializer() = delete;
    // Define the path to the users.csv file.
    static const QString USERS_FILE_PATH;
};

#endif // USERMANAGERINITIALIZER_H
