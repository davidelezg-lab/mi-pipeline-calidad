pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Obteniendo codigo desde GitHub...'
            }
        }

        stage('Clean') {
            steps {
                echo 'Limpiando ficheros antiguos de cobertura...'

                bat 'del /Q *.gcda 2>nul'
                bat 'del /Q *.gcno 2>nul'
                bat 'del /Q .gcov 2>nul'
            }
        }

        stage('Build') {
            steps {

                echo 'Compilando aplicacion...'

                bat '"C:\msys64\ucrt64\bin\g++.exe" --coverage main.cpp -o app.exe'

                bat 'app.exe'
            }
        }

        stage('Test') {
            steps {

                echo 'Compilando y ejecutando tests...'

                bat '"C:\msys64\ucrt64\bin\g++.exe" --coverage test.cpp -o test.exe'

                bat 'test.exe > resultado-tests.txt'

                bat 'type resultado-tests.txt'
            }
        }

        stage('Coverage') {
            steps {

                echo 'Generando cobertura...'

                bat '''
                for %%F in (.gcno) do (
                    echo Procesando %%F
                    "C:\msys64\ucrt64\bin\gcov.exe" "%%F"
                )
                '''

                bat 'dir .gcov'
            }
        }

        stage('SonarCloud') {
            steps {

                echo 'Ejecutando analisis SonarCloud...'

                withSonarQubeEnv('SonarCloud') {
                    bat '"C:\sonar-scanner\bin\sonar-scanner.bat"'
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

                archiveArtifacts artifacts: 'app.exe,test.exe,resultado-tests.txt,.gcov',
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

        always {
            echo 'Fin de la ejecucion.'
        }
    }
}
