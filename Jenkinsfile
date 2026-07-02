pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {

        stage('Checkout') {
            steps {
                echo 'Obteniendo codigo desde GitHub...'
            }
        }

        stage('Clean') {
            steps {
                echo 'Limpiando ficheros antiguos...'

                bat 'del /Q *.gcda 2>nul'
                bat 'del /Q *.gcno 2>nul'
                bat 'del /Q *.gcov 2>nul'
                bat 'del /Q resultado-tests.txt 2>nul'
            }
        }

        stage('Build') {
            steps {

                echo 'Compilando aplicacion principal...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage main.cpp -o app.exe'

                echo 'Ejecutando aplicacion principal...'

                bat 'app.exe'
            }
        }

        stage('Test') {
            steps {

                echo 'Compilando tests...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage test.cpp -o test.exe'

                echo 'Ejecutando tests...'

                bat 'test.exe > resultado-tests.txt'

                bat 'type resultado-tests.txt'
            }
        }

        stage('Coverage') {
            steps {

                echo 'Mostrando ficheros de cobertura...'

                bat 'dir *.gcno'
                bat 'dir *.gcda'

                echo 'Generando informes gcov...'

                bat '''
                for %%F in (*.gcno) do (
                    echo Procesando %%F
                    "C:\\msys64\\ucrt64\\bin\\gcov.exe" "%%F"
                )
                '''

                bat 'dir *.gcov'
            }
        }

        stage('SonarCloud') {
            steps {

                echo 'Analizando con SonarCloud...'

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

                archiveArtifacts(
                    artifacts: 'app.exe,test.exe,resultado-tests.txt,*.gcov,*.gcno,*.gcda',
                    fingerprint: true
                )
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
