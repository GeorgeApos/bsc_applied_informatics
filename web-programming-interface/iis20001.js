const configuration = document.querySelector('input[name="Configuration"]');
const facoption = document.querySelector('input[name="FactoryOption"]');
const dealoption = document.querySelector('input[name="DealerOption"]');


document.getElementById('result').addEventListener('click', function (ev) {
    let message = 0;

    if(document.getElementById('gtmanual').checked){
        message += 17790;
    }else if(document.getElementById('gtauto').checked){
        message += 18590;
    }else if(document.getElementById('gtsmanual').checked){
        message += 22455;
    }else if(document.getElementById('gtsports').checked){
        message += 23155;
    }else{
        message += 0;
    }

    if(document.getElementById('option1').checked){
        message += 1235;
    }else if(document.getElementById('option2').checked){
        message += 3354;
    }else if(document.getElementById('option3').checked){
        message += 0;
    }else{
        message += 0;
    }

    if (document.getElementById('deloption1').checked == true) {
        message += 550;
    }

    if (document.getElementById('deloption2').checked == true) {
        message += 399;
    }

    if (document.getElementById('deloption3').checked == true) {
        message += 295;
    }

    document.getElementById("resultText").innerHTML = message;
});