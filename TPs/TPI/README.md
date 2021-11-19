# AED1 - TPI

- Materia: Algoritmos y Estructuras de Datos 1
- Cursada: 2do cuatrimestre 2021 (virtual)
- Comisión: 3
- Grupo 2:
    - Valentina Durán (974/21)
    - Rafael Romani (775/21)
    - Jonathan Bekenstein (348/11)

## Decisiones tomadas

1. Modificamos `definiciones.h` agregando defines y tipos.
2. Decidimos pasar todas las secuencias por referencia porque entendemos que así es más eficiente.
3. Tests agregados o corregidos:
    1. Agregado: `esEncuestaValidaTEST.invalidaHogaresSinIndividuos`
    2. Agregado: `esEncuestaValidaTEST.invalidaMasDe20MiembrosEnElHogar`
    3. Agregado: `esEncuestaValidaTEST.invalidaUltimoAtributoDeHogarFueraDeRango`
    4. Corregido: `esEncuestaValidaTEST.invalidaDormitoriosMayoresAHabitaciones` (El th usado en el test no tenía el
       mismo trimestre para todos los hogares, entonces por la lógica de corto-circuito, dependiendo del orden de los
       chequeos en la implementación de esEncuestaValida, podía devolver false antes de realmente chequear la cantidad
       de dormitorios. Así que modificamos el th del test y les colocamos el mismo trimestre a todos los hogares.)
    5. Agregado: `creceElTeleworkingEnCiudadesGrandesTEST.nadieTrabaja`
