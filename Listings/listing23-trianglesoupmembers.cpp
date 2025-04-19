/* Constructor: initialize a triangleSoup object to all zeros */
TriangleSoup();

/* Destructor: clean up allocated data in a triangleSoup object */
~TriangleSoup();

/* Clean up allocated data in a triangleSoup object */
void clean();

/* Create a very simple demo mesh with a single triangle */
void createTriangle();

/* Create a simple box geometry */
void createBox(float xsize, float ysize, float zsize);

/* Create a sphere (approximated by polygon segments) */
void createSphere(float radius, int segments);

/* Load geometry from an OBJ file */
void readOBJ(const std::string& filename);

/* Print data from a triangleSoup object, for debugging purposes */
void print();

/* Print information about a triangleSoup object (stats and extents) */
void printInfo();

/* Render the geometry in a triangleSoup object */
void render();