// void SimulacionCola::generarPdf(){
//     ostringstream html;
//      html << "<html>"
//             "<head><title>Tabla de Tiempos (SIMULACION)</title></head>"
//             "<body>"
//             "<p> Ord del Cliente: Ord  </p>"
//             "<p> Tiempo de Llegada: TmpLlegada </p>"
//             "<p> Tiempo de Espera: TmpEspera </p>"
//             "<p> Tiempo no trabajado del Cajero: TmpnCajero </p>"
//             "<p> Tiempo de Servicio: TmpServicio </p>"
//             "<p> Tiempo de Salida: TmpSalida </p>"
//             "<p> Tiempo entre Llegadas: TmpEntLlegadas </p>"
//             "<p><table><thead><tr>"
//             "<th>Ord  &nbsp; &nbsp;</th>"
//             "<th>TmpLlegada  &nbsp; &nbsp;</th>"
//             "<th>TmpEspera  &nbsp; &nbsp;</th>"
//             "<th>TmpnCajero  &nbsp; &nbsp;</th>"
//             "<th>TmpServicio  &nbsp; &nbsp;</th>"
//             "<th>TmpSalida  &nbsp; &nbsp;</th>"
//             "<th>TmpEntLlegadas  &nbsp; &nbsp;</th>"
//             "<th>"
//             "</table></p></tr></thead><tbody>";
            
//     clientes.recorrerCola([&](Nodo<Cliente> *cliente){
//         Movimiento mov; 
//         Cliente cl; 
//         int tmp; 
//         cl = cliente->getDato();
//         mov = cl.getMov();
//         html<<"</br><td> ___________________________</td>";
//         html << "</br> <tr>";
//             tmp = cl.getOrd();
//            html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//            tmp = mov.getTmpLlegada();
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//             tmp = mov.getTmpEspera();
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//             tmp = *(cajero.getTmpNTraCaj() + cliente->getDato().getOrd()-1);
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//             tmp = *(cajero.getTmpServicio() + cliente->getDato().getOrd()-1);
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//             tmp = mov.getTmpSalida();
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//              tmp = mov.getTmpEntLlegada();
//             html<< "<td>  "+std::to_string(tmp)+compararValores(tmp);
//             html<< "</tr>  ";
//     });
//     double tmp; 

//     string val = "El promedio de tiempo de espera es:  ";
//     tmp = promediarEspera();
//     tmp = redondear(tmp,2);
//     html<<"</br></br><td>"+val+std::to_string(tmp)+"</td>";

//     val = "El promedio de tiempo que no trabaja el cajero es: ";
//     tmp = promediarNoTCajero();
//     tmp = redondear(tmp,2);
//     html<<"</br></br><td>"+val+std::to_string(tmp)+"</td>";

//     val = "El numero de clientes promedio en la cola es: ";
//     tmp = calcularClientes();
//     tmp = redondear(tmp,2);
//     html<<"</br></br><td>"+val+std::to_string(tmp)+"</td>";

//     val = "El promedio de tiempo de servicio es: ";
//     tmp = promediarServicio();
//     tmp = redondear(tmp,2);
//     html<<"</br></br><td>"+val+std::to_string(tmp)+"</td>";

//     html<<"</body></html>";
//     std::ostringstream plain;
//     std::string html_filename = "TablaSimulacion.html";
//     std::string pdf_filename = "TablaSimulacion3.pdf";
//     std::ofstream out_html(html_filename, std::ios::trunc);
//     std::ofstream out_txt("TablaSimulacion.txt", std::ios::trunc);
//     out_html << html.str();
//     out_txt.close();
//     out_html.close();

//     if (std::ifstream(pdf_filename.c_str()).good()) {
//         std::remove(pdf_filename.c_str());
//     }
//     system((std::string("wkhtmltopdf") + " " + html_filename + " " + pdf_filename).c_str());
//     std::cout << std::endl << "archivo pdf generado!";
// }