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
3. Atlikta programos spartos analizė taikant std::vector ir std::list konteinerius: <br>
Matuoti trys programos atlikimo etapai – visų studentų surūšiavimas į išlaikiusius ir neišlaikiusius, duomenų išrikiavimas pagal galutinį pažymį, rezultatų įrašymas į failus. Visi bandymai atlikti su failais, turinčiais 5 ND pažymius bei rikiavimas vykdomas pagal vidurkio reikšmes. Kiekvienas testas atliktas 5 kartus.
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
