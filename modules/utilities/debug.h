#ifndef DEBUG_H
    #define DEBUG_H

    #ifdef DEBUG
        #define PNT_DEBUG(label, condition, expectedBool) (printf("%s: %s\n", label, (condition == expectedBool)?"TRUE":"FALSE"))
        #define PNT_BOOL(label, bool) (printf("%s: %s\n", label, (bool)?"TRUE":"FALSE"))
        #define PNT_SIZE(label, size) (printf("%s size --> %d\n"))
        #define TAG(what) (printf("TAGGED: %s\n", what))
    #else
        #define PNT_DEBUG(label, condition, expectedBool) 
        #define PNT_BOOL(label, bool)
        #define PNT_SIZE(label, size)
        #define TAG(what)

    #endif
#endif

