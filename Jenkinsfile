pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {

                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {

                bat 'make'
            }
        }
        stage('Test') {
            steps {

                echo 'Running tests...'
            }
        }
        stage('Upload to Nexus') {
            steps {
                sh """
                    curl -u ${NEXUS_USERNAME}:${NEXUS_PASSWORD} --upload-file target/myprogram.exe \
                        ${NEXUS_URL}/repository/${NEXUS_REPO}/myprogram.exe
                        """
                }

            }
        }
    }
}
