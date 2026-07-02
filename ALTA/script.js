// Função que busca os dados mais recentes
function atualizarDados() {

    // Adiciona um número diferente na URL para evitar cache
    fetch("dados.json?t=" + new Date().getTime())

        .then(function(resposta) {

            if (!resposta.ok) {
                throw new Error("Não foi possível carregar os dados.");
            }

            return resposta.json();

        })

        .then(function(dados) {

            document.getElementById("nivel").textContent =
                dados.distancia + " cm";

            document.getElementById("status").textContent =
                dados.status;

            document.getElementById("hora").textContent =
                "Última atualização: " +
                new Date().toLocaleTimeString("pt-BR");

        })

        .catch(function(erro) {

            console.error(erro);

            document.getElementById("nivel").textContent = "--";
            document.getElementById("status").textContent = "Sem conexão";
            document.getElementById("hora").textContent = "";

        });

}

// Atualiza assim que a página abre
atualizarDados();

// Atualiza automaticamente a cada segundo
setInterval(atualizarDados, 1000);