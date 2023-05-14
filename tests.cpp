#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "vector.lib.h"

TEST_CASE("average ir median") {
    SECTION("Average skaiciavimas su pažymiai ir egzamino ivertinimu") {
        vector<int> vec = {7,7,7,7};
        studentas st;
        st.setPazymiai(vec);
        st.setEgzaminas(7);
        st.aver();
        REQUIRE(st.getGalutinis() == 7);
    }
    SECTION("Median skaiciavimas su pažymiais ir egzamino ivertinimu")
    {
        vector<int> vec = {10,10,10,10};
        studentas st;
        st.setPazymiai(vec);
        st.setEgzaminas(10);
        st.medi();
        REQUIRE(st.getMediana() == 10);
    }
    SECTION("Median skaičiavimas, kai egzamino pažymio nėra")
    {
        vector<int> vec = {10,10,10,10};
        studentas st;
        st.setPazymiai(vec);
        st.medi();
        REQUIRE(st.getMediana() == 4);
    }
}