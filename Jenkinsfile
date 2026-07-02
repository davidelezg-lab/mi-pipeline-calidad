pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {

        stage('Build') {
            steps {
                echo 'Compilando aplicacion principal con cobertura...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage main.cpp -o app.exe'
            }
        }

        stage('Test') {
            steps {

                echo 'Compilando tests con cobertura...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage test.cpp -o test.exe'

                echo 'Ejecutando tests...'

                bat 'test.exe > resultado-tests.txt'

                bat 'type resultado-tests.txt'
            }
        }

        stage('Generar Cobertura') {
            steps {

                echo 'Generando informe gcov...'

                bat '"C:\\msys64\\ucrt64\\bin\\gcov.exe" main.cpp'

                bat 'dir *.gcov'
            }
        }

        stage('Analisis SonarCloud') {
            steps {

                echo 'Enviando analisis a SonarCloud...'

                withSonarQubeEnv('SonarCloud') {
                    bat '"C:\\sonar-scanner\\bin\\sonar-scanner.bat"'
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

                echo 'Publicando artefactos...'

                archiveArtifacts artifacts: '*.gcov,app.exe,test.exe,resultado-tests.txt',
                                 fingerprint: true
            }
        }
    }

    post {

        success {
            echo 'Pipeline completada correctamente.'
        }

        failure {
            echo 'Pipeline fallida.'
        }

        unstable {
            echo 'Pipeline inestable.'
        }

        always {
            echo 'Fin de la ejecucion.'
        }
    }
}
