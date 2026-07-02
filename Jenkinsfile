pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {
        stage('Build') {
            steps {
                echo 'Compilando aplicacion principal...'
                bat '"C:\msys64\ucrt64\bin\g++.exe" main.cpp -o app.exe'
            }
        }

        stage('Test') {
            steps {
                echo 'Compilando y ejecutando tests...'
                bat '"C:\msys64\ucrt64\bin\g++.exe" test.cpp -o test.exe'
                bat 'test.exe > resultado-tests.txt'
                bat 'type resultado-tests.txt'
            }
        }

        stage('Analisis SonarCloud') {
            steps {
                echo 'Ejecutando analisis estatico con SonarCloud...'
                withSonarQubeEnv('SonarCloud') {
                    bat 'sonar-scanner'
                }
            }
        }

        stage('Quality Gate') {
            steps {
                echo 'Esperando resultado del Quality Gate...'
                timeout(time: 5, unit: 'MINUTES') {
                    waitForQualityGate abortPipeline: true
                }
            }
        }

        stage('Publish') {
            steps {
                echo 'Publicando artefactos aprobados...'
                archiveArtifacts artifacts: 'app.exe, test.exe, resultado-tests.txt', fingerprint: true
            }
        }
    }

    post {
        success {
            echo 'Pipeline finalizada correctamente. Codigo validado y artefactos publicados.'
        }

        failure {
            echo 'Pipeline fallida. Revisar logs, tests o Quality Gate.'
        }

        unstable {
            echo 'Pipeline inestable. Revisar resultados de pruebas.'
        }
    }
}
