**Matas Kantautas** <br>
**Vilniaus universiteto duomenų mokslo programa** <br>
**Objektinio programavimo 1 laboratorinis darbas**

**V0.1** <br>
1. Sukurta galutinio balo skaičiavimo sistema;
2. Sukurta galimybė pasirinkti skaičiuoti galutinį balą pagal vidurkį arba medianą;
3. Sukurtas atsitiktinių pažymių generavimas;
4. Sukurta galimybė nuskaityti duomenis iš .txt failo;
5. Pridėta išvestis į vartotojo nurodomą failą;
6. Pridėtas rezultatų rikiavimas pagal pavardę ir vardą.

**V0.2** <br>
1. Sukurta studentų duomenų generavimo programa (failai su atitinkamai 1000, 10000, 100000, 1000000, 10000000 eilučių duomenų);
2. Sukurta studentų išskaidymas į išlaikiusius ir neišlaikiusius, šių grupių rezultatai pateikiami skirtinguose failuose;
3. Funkcijos ir struktūros perkeltos į atskirus failus;
4. Pridėta galimybė vartotojui pasirinkti parametrą, pagal kurį rikiuoti rezultatus;
5. Sukurta programos spartos analizė.

**V0.3** <br>
1. Pridėta galimybė įrašius duomenis ranka pamatyti objekto adresą atmintyje;
2. Pridėta galimybė duomenis talpinti ir std::list struktūroje;
3. Atlikta programos spartos analizė taikant std::vector ir std::list konteinerius. <br>

Analizės apžvalga: matuoti trys programos atlikimo etapai – visų studentų surūšiavimas į išlaikiusius ir neišlaikiusius, duomenų išrikiavimas pagal galutinį pažymį, rezultatų įrašymas į failus. Visi bandymai atlikti su failais, turinčiais 5 ND pažymius bei rikiavimas vykdomas pagal vidurkio reikšmes. Visi testai atlikti 5 kartus, jų vidurkius galite matyti lentelėse (duomenys pateikti sekundėmis).

Rezultatai:
<table>
  <caption><b>Surūšiavimas į dvi grupes</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0014</td>
      <td>0,0014</td>
      <td>-</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0073</td>
      <td>0,0068</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,0471</td>
      <td>0,071</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>0,4304</td>
      <td>0,4971</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>4,1767</td>
      <td>5,372</td>
      <td>+</td>
    </tr>
  </tbody>
</table>

<table>
  <caption><b>Išrikiavimas pagal galutinį balą</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0009</td>
      <td>0,0009</td>
      <td>-</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0043</td>
      <td>0,0051</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,0331</td>
      <td>0,0647</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>0,3208</td>
      <td>0,8092</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>4,1193</td>
      <td>11,1987</td>
      <td>+</td>
    </tr>
  </tbody>
</table>

<table>
  <caption><b>Įrašymas į failą</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0101</td>
      <td>0,0148</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0359</td>
      <td>0,0385</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,2087</td>
      <td>0,2386</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>1,6276</td>
      <td>1,8461</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>19,9074</td>
      <td>19,2783</td>
      <td>-</td>
    </tr>
  </tbody>
</table>

Išvados: Su nedideliais duomenų kiekiais abu konteineriai dirba apylygiai, tačiau nuo 100.000 įrašų matomas ryškus std::vector pranašumas prieš std::list (su viena išimtimi įrašyme į failus 10 mln. eilučių atveju). Didžiausias skirtumas matomas rikiavimo užduotyje, kurią vektorius atlieka net 2–3 kartus greičiau nei sąrašas.

Kompiuterio, su kuriuo atlikta analizė, parametrai: 1,2 GHz procesorius, 8 GB RAM, SSD 238 GB.
