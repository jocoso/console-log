#ifndef DEBUG_H
    #define DEBUG_H

    #ifdef DEBUG
        #define PNT_DEBUG(label, condition, expectedBool) (printf("%s: %s\n", label, (condition == expectedBool)?"TRUE":"FALSE"))
        #define TAG() (printf("tag"))
    #else
        #define PNT_DEBUG(label, condition, expectedBool) 
        #define TAG()

    #endif
#endif

