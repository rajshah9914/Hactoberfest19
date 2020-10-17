
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        // $t=[];
        // $t=$(this.responseXml).find("div.cb-col-100 div.cb-hm-scg-blk").html();
        // document.getElementById("abc").innerHTML = $t;
        var xmlDoc = this.response;
        console.log(xmlDoc);      
        document.getElementById("abc").innerHTML =xmlDoc;
      }
    };
    xhttp.open("GET", "https://www.cricbuzz.com/cricket-match/live-scores", true);
    xhttp.send();

    function xyz(){
        window.open("https://www.cricbuzz.com/cricket-match/live-scores");
    }