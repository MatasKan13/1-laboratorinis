#include <chrono>

class Timer {
    private:
        using Laikrodis = std::chrono::high_resolution_clock;
        using Trukme = std::chrono::duration<double>;
        std::chrono::time_point<Laikrodis> start;
    
    public:
        Timer() : start{Laikrodis::now()} {};

        void reset() {
            start = Laikrodis::now();
        }

        double elapsed() const {
            return Trukme (Laikrodis::now() - start).count();
        }
};
