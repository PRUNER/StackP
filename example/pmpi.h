#define BEFORE_CALL \
  do { \
    printf("Before %s (PMPI_ID: %d)\n", __func__, PMPI_ID); \
  } while(0)

#define AFTER_CALL \
  do { \
    printf("After  %s (PMPI_ID: %d)\n", __func__, PMPI_ID); \
  } while(0)

